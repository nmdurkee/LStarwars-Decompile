/* Ghidra analysis pseudocode, not original source.
 * ev_bdbc2bae44bf5487d6b3a1a9f152189c4c55001891ec534863a9f12b45a65f9f
 * Entry: 0x5a86a0; label: FUN_005a86a0
 */

bool FUN_005a86a0(int *param_1)

{
  if (((param_1 != (int *)0x0) && (*param_1 != 0)) && (*(char *)(*param_1 + 8) == '\x02')) {
    return (char)param_1[1] != '\0';
  }
  return true;
}

