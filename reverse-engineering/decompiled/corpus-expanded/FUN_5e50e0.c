/* Ghidra pseudocode, not original source.
 * ev_dd2b431ee7d7df08292740893bb7b99558b7953fea1da99d97b81497b86ab5e2
 * Entry: 0x5e50e0; label: FUN_005e50e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005e50e0(ushort *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  *param_1 = *param_1 & 0xfffe;
  FUN_005de220(param_1);
  puVar2 = (undefined4 *)FUN_00547580(DAT_00973ff8,0);
  while (puVar1 = puVar2, puVar1 != (undefined4 *)0x0) {
    puVar2 = (undefined4 *)FUN_00547580(DAT_00973ff8,puVar1);
    if ((ushort *)puVar1[1] == param_1) {
      *(ushort *)*puVar1 = *(ushort *)*puVar1 & 0xfffe;
      FUN_005de220(*puVar1);
      FUN_005474d0(puVar1);
    }
  }
  return;
}

