/* Ghidra analysis pseudocode, not original source.
 * ev_defa56967bea180293c2bb16677406271af3ce5a827b3a721aa49801cdb81f39
 * Entry: 0x6cbc00; label: FUN_006cbc00
 */

void FUN_006cbc00(undefined4 *param_1)

{
  for (param_1 = (undefined4 *)*param_1; param_1 != (undefined4 *)0x0;
      param_1 = (undefined4 *)*param_1) {
    FUN_006c94a0(param_1 + 2,0xff800000);
  }
  return;
}

