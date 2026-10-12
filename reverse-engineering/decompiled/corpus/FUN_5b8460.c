/* Ghidra analysis pseudocode, not original source.
 * ev_379977b8d9e5873865d2e50b4d7e474067c4ddbccc47084b5a50182ca7f5b25f
 * Entry: 0x5b8460; label: FUN_005b8460
 */

float10 FUN_005b8460(float param_1,float param_2,float param_3,float param_4,float param_5)

{
  return (float10)(param_2 +
                  (param_3 * 0.5 + param_1 * 0.5 + -param_2) * param_5 * param_5 +
                  (param_4 / 6.0 + -param_3 * 0.5 + -param_1 / 6.0 + param_2 * 0.5) *
                  param_5 * param_5 * param_5 +
                  (-param_1 / 3.0 + -param_2 * 0.5 + param_3 + -param_4 / 6.0) * param_5);
}

