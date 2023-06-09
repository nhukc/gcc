// { dg-options "-fdiagnostics-show-caret -fdiagnostics-escape-format=unicode" }

  /* { dg-warning "null character\\(s\\) ignored" } */
/* { dg-begin-multiline-output "" }
 <U+0000>
 ^~~~~~~~
   { dg-end-multiline-output "" } */

/* Stray UTF-8 trailing byte: */
� /* { dg-error "stray '.200' in program" } */
/* { dg-begin-multiline-output "" }
 <80>
 ^~~~
   { dg-end-multiline-output "" } */

const char *fmt = "\"; /* { dg-warning "unknown escape sequence: '.001'" } */
/* { dg-begin-multiline-output "" }
 const char *fmt = "\<U+0001>";
                              ^
   { dg-end-multiline-output "" } */
