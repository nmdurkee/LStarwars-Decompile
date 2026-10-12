/* Ghidra analysis pseudocode, not original source.
 * ev_56bf9e76ab0c031fab8380995f005739ca3b697a310321db3c480b01a4d86e23
 * Entry: 0x5e50e0; label: FUN_005e50e0
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

