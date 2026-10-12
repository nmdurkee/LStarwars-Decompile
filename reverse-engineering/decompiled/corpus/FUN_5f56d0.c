/* Ghidra analysis pseudocode, not original source.
 * ev_7cb997f3f06904df49554a3614ea3c2031937e13b6d92041b838b169c363bf2a
 * Entry: 0x5f56d0; label: FUN_005f56d0
 */

void FUN_005f56d0(int param_1)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  bool bVar6;
  undefined1 *local_218 [2];
  int local_210;
  undefined1 local_20c [272];
  int local_fc;
  
  iVar2 = FUN_005f3c80(*(undefined4 *)(param_1 + 0x78),&stack0x0000000c);
  iVar5 = 0;
  if ((((iVar2 == 0) || (DAT_0080bab4 == 0)) || (*(int *)(iVar2 + 0x18) == 0)) ||
     (bVar1 = true, DAT_0080ba58 == 0)) {
    bVar1 = false;
  }
  bVar6 = DAT_009718dc == 0;
  if (((*(byte *)(param_1 + 0x76) & 1) == 0) && (DAT_00973fd0 == 0)) {
    local_218[0] = *(undefined1 **)(param_1 + 0x78);
    if (local_218[0] == (undefined1 *)0x0) {
      local_fc = param_1;
      local_218[0] = local_20c;
    }
    iVar4 = 0;
    if (0 < *(int *)(param_1 + 0x6c)) {
      do {
        local_210 = iVar5 + *(int *)(param_1 + 0x70);
        if ((((*(byte *)(iVar5 + 0xb8 + *(int *)(param_1 + 0x70)) & 2) != 0) &&
            ((bVar6 || ((*(byte *)(*(int *)(local_210 + 0xc0) + *(int *)(param_1 + 0x48)) & 0x20) !=
                        0)))) &&
           ((!bVar1 ||
            ((iVar3 = *(int *)(local_210 + 0xc0),
             (*(byte *)(*(int *)(param_1 + 0x48) + iVar3) & 8) != 0 ||
             ((*(byte *)((iVar3 >> 3) + *(int *)(iVar2 + 0x1c)) >> ((byte)iVar3 & 7) & 1) != 0))))))
        {
          if ((local_210 == 0) ||
             ((iVar3 = *(int *)(local_210 + 0xc4), iVar3 == -1 || (iVar3 == 0)))) {
            iVar3 = local_210 + 0x40;
          }
          FUN_005f0f00(local_218,iVar3,0,0,0);
        }
        iVar4 = iVar4 + 1;
        iVar5 = iVar5 + 0xd0;
      } while (iVar4 < *(int *)(param_1 + 0x6c));
    }
  }
  return;
}

