/* Ghidra analysis pseudocode, not original source.
 * ev_379977b8d9e5873865d2e50b4d7e474067c4ddbccc47084b5a50182ca7f5b25f
 * Entry: 0x5b7c20; label: FUN_005b7c20
 */

float10 FUN_005b7c20(uint param_1)

{
  if ((param_1 & 0x80000000) != 0) {
    return (float10)-1.0;
  }
  return (float10)1.0;
}

