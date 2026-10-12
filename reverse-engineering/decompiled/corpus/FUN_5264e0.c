/* Ghidra analysis pseudocode, not original source.
 * ev_45ac563217612fbe2426642b00b9c96cf69ca1c78f087433beffcbe1e9bd0306
 * Entry: 0x5264e0; label: FUN_005264e0
 */

void FUN_005264e0(undefined4 param_1,int param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  undefined8 uVar5;
  
  iVar2 = DAT_009238e4;
  if ((((param_2 != 0) && (*(int *)(DAT_009238e4 + 0x4868) != 0)) &&
      (iVar1 = *(int *)(*(int *)(DAT_009238e4 + 0x4868) + 0x28), iVar1 != 0)) &&
     (*(uint *)(param_2 + 0xc) < 0x40)) {
    uVar5 = __allshl();
    uVar4 = (uint)((ulonglong)uVar5 >> 0x20);
    uVar3 = (uint)uVar5;
    iVar2 = *(int *)(*(int *)(iVar2 + 0x4868) + 0x28);
    if ((*(uint *)(iVar1 + 0x10) & uVar3) != 0 || (*(uint *)(iVar1 + 0x14) & uVar4) != 0) {
      *(uint *)(iVar2 + 0x10) = *(uint *)(iVar2 + 0x10) & ~uVar3;
      *(uint *)(iVar2 + 0x14) = *(uint *)(iVar2 + 0x14) & ~uVar4;
      *(byte *)(param_2 + 0x11) = *(byte *)(param_2 + 0x11) & 0xfe;
      return;
    }
    *(uint *)(iVar2 + 0x10) = *(uint *)(iVar2 + 0x10) | uVar3;
    *(uint *)(iVar2 + 0x14) = *(uint *)(iVar2 + 0x14) | uVar4;
    *(byte *)(param_2 + 0x11) = *(byte *)(param_2 + 0x11) | 1;
  }
  return;
}

