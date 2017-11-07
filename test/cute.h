/*
 * MIT License
 *
 * Copyright (c) 2017 Lucas Abel <www.github.com/uael>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#ifndef CUTE_H__
# define CUTE_H__

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#if defined _MSC_VER || defined __ICL || defined __ICC || defined __INTEL_COMPILER
# define CUTE_FORCEINLINE __forceinline
# define CUTE_CONSTCALL
#elif defined __GNUC__ || defined __clang__
# define CUTE_FORCEINLINE inline __attribute__((__always_inline__))
# define CUTE_CONSTCALL __attribute__((__const__))
#else
# define CUTE_FORCEINLINE
# define CUTE_CONSTCALL
#endif

#if defined __GNUC__ || defined __clang__
# define CUTE_UNUSED __attribute__((unused))
#elif defined __LCLINT__
# define CUTE_UNUSED /*@unused@*/
#else
# define CUTE_UNUSED
#endif

#if defined _WIN32 || defined __WIN32__ || defined _WIN64
# define RESET
# define RED
# define GREEN
#else
# define RESET "\033[0m"
# define RED "\033[31m"
# define GREEN "\033[32m"
#endif

#define CUTE_SUCCESS EXIT_SUCCESS
#define CUTE_FAILURE EXIT_FAILURE

#define CUTEST_DATA struct CUTEST

typedef CUTEST_DATA CUTEST_t;

#define CUTEST_SETUP void test_setup(CUTEST_t *self)
#define CUTEST_TEARDOWN void test_teardown(CUTEST_t *self)

char __cute_str_err[255];

#define S1(x) #x
#define S2(x) S1(x)
#define LOCATION __FILE__ ":" S2(__LINE__)
#define ASSERT(expr) do if (!(expr)) return LOCATION " -> " #expr; while (0)
#define FAIL(msg) return (msg);
#define ASSERT_EQ(e, g) \
  do { \
    long long __expect, __got; \
    __expect = (long long) (e); \
    __got = (long long) (g); \
    if (__expect != __got) { \
      sprintf(__cute_str_err, LOCATION " -> %lli != %lli", __expect, __got); \
      return __cute_str_err; \
    } \
  } while (0)
#define ASSERT_NEQ(v, e) do if ((v) == (e)) return LOCATION " -> " #v " != " #e; while (0)
#define ASSERT_SEQ(expected, got) ASSERT_EQ(0, strcmp(got, expected))
#define ASSERT_CLOSE(v, e, p) do if (double_close(v, e, p) == 0) return LOCATION " -> " #v " == " #e; while (0)

#define CUTEST_PADDING "................................."
#define CUTEST_FN(suite, name) suite ## _ ## name ## _test
#define CUTEST_RUN(suite, name, should_fail) \
  do if (test_run(&test, #suite ":" #name, sizeof(#suite ":" #name)-1, should_fail, CUTEST_FN(suite, name)) == CUTE_FAILURE) \
      return CUTE_FAILURE; \
  while (0)
#define CUTEST_PASS(suite, name) CUTEST_RUN(suite, name, 0)
#define CUTEST_FAIL(suite, name) CUTEST_RUN(suite, name, 1)
#define CUTEST(suite, name) static const char *CUTEST_FN(suite, name)(CUTE_UNUSED CUTEST_t *self)

CUTEST_SETUP;

CUTEST_TEARDOWN;

CUTE_FORCEINLINE CUTE_CONSTCALL int
test_run(CUTEST_t *self, const char *id, unsigned id_len,
         unsigned char should_fail,
         const char *(*test_fn)(CUTEST_t *)) {
    const char *result;
    int s = sizeof(CUTEST_PADDING) - id_len - 1;

    printf("Test:     %s %*.*s   ", id, s, s, CUTEST_PADDING);
    test_setup(self);
    result = test_fn(self);
    test_teardown(self);

    if (should_fail) {
        if (result) {
            printf(GREEN "[" RED "FAIL" GREEN " ~>  OK] ‘%s’" RESET "\n", result);
            return CUTE_SUCCESS;
        }
        printf(RED "[FAIL ~> NOK] ‘%s’" RESET "\n", result);
        return CUTE_FAILURE;
    }
    if (result) {
        printf(RED "[PASS ~> NOK] ‘%s’" RESET "\n", result);
        return CUTE_FAILURE;
    }
    puts(GREEN "[PASS ~>  OK]" RESET);
    return CUTE_SUCCESS;
}

CUTE_FORCEINLINE CUTE_CONSTCALL int
double_close(double val, double expect, double precision) {
    return val >= expect - precision && val <= expect + precision;
}

#endif /* CUTE_H__ */
