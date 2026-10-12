/* Ghidra analysis pseudocode, not original source.
 * ev_2c014b146e9258db07d80d50b3912bad4b2773c74b3e67189abd65c219d7972f
 * Entry: 0x5ab730; label: FUN_005ab730
 */

void FUN_005ab730(undefined4 param_1,int *param_2)

{
  ushort uVar1;
  ushort *puVar2;
  int iVar3;
  
  if (param_2 != (int *)0x0) {
    iVar3 = 0;
    if ((short)param_2[2] != 0) {
      puVar2 = (ushort *)(*param_2 + 0x13a);
      do {
        if ((*puVar2 & 0x100) != 0) {
          uVar1 = FUN_0056aa40(param_1,(int)(short)puVar2[-0xb]);
          *puVar2 = *puVar2 & 0xfeff;
          puVar2[-0xb] = uVar1;
        }
        iVar3 = iVar3 + 1;
        puVar2 = puVar2 + 0x9e;
      } while (iVar3 < (int)(uint)*(ushort *)(param_2 + 2));
    }
  }
  return;
}

