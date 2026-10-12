/* Ghidra pseudocode, not original source.
 * ev_f26efce709548f397f112d14bef56d8f0f3486015c16e671b302622d1d4cb319
 * Entry: 0x650360; label: FUN_00650360
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00650360(undefined4 param_1,uint param_2)

{
  uint uVar1;
  
  uVar1 = 0;
  if (param_2 != 0) {
    do {
      uVar1 = uVar1 + 1;
    } while (uVar1 < param_2);
  }
  return;
}

