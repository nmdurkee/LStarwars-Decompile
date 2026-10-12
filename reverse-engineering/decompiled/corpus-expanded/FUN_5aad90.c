/* Ghidra pseudocode, not original source.
 * ev_724cabe4f5fc1a17992688438315818e84a5f5e3e3395d254642ecf9571b826a
 * Entry: 0x5aad90; label: FUN_005aad90
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005aad90(undefined4 param_1)

{
  int iVar1;
  
  if (DAT_0095df4c != 0) {
    for (iVar1 = FUN_004f1440(DAT_0095df4c + 0x10); iVar1 != 0;
        iVar1 = FUN_004f1460(DAT_0095df4c + 0x10,iVar1)) {
      if ((*(byte *)(iVar1 + 0x36) & 1) != 0) {
        FUN_00559ee0(param_1,DAT_00805d44,0,iVar1);
        *(ushort *)(iVar1 + 0x36) = *(ushort *)(iVar1 + 0x36) | 2;
      }
    }
  }
  return;
}

