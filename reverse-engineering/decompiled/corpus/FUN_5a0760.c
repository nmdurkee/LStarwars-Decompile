/* Ghidra analysis pseudocode, not original source.
 * ev_ecc8ce98e599e83956a160512bc3e9e95348504114ce7e145bc7e138d08a4c20
 * Entry: 0x5a0760; label: FUN_005a0760
 */

ushort * FUN_005a0760(undefined4 param_1,undefined4 param_2,int param_3,uint param_4)

{
  ushort *puVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  puVar1 = (ushort *)0x0;
  if ((param_4 != 0) &&
     (puVar1 = (ushort *)FUN_00552670(param_1,param_2,0x14), puVar1 != (ushort *)0x0)) {
    puVar1[2] = (ushort)param_4;
    *puVar1 = (ushort)param_3;
    uVar2 = FUN_00552670(param_1,param_2,(param_4 & 0xffff) * 0x28);
    *(undefined4 *)(puVar1 + 4) = uVar2;
    if (param_3 != 0) {
      uVar2 = FUN_00552670(param_1,param_2,(uint)puVar1[2] * (uint)*puVar1);
      *(undefined4 *)(puVar1 + 8) = uVar2;
    }
    iVar5 = 0;
    if (puVar1[2] != 0) {
      iVar3 = *(int *)(puVar1 + 4);
      iVar4 = 0;
      do {
        *(undefined4 *)(iVar4 + iVar3) = *(undefined4 *)(puVar1 + 6);
        iVar3 = *(int *)(puVar1 + 4);
        *(int *)(puVar1 + 6) = iVar4 + iVar3;
        iVar5 = iVar5 + 1;
        iVar4 = iVar4 + 0x28;
      } while (iVar5 < (int)(uint)puVar1[2]);
    }
  }
  return puVar1;
}

