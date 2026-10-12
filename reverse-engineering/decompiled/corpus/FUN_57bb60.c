/* Ghidra analysis pseudocode, not original source.
 * ev_df641eda8072cee71ca3b2626b4685e3428f565924a572e6fdc3ba5eae4c5d68
 * Entry: 0x57bb60; label: FUN_0057bb60
 */

void FUN_0057bb60(int param_1)

{
  byte *pbVar1;
  int iVar2;
  int iVar3;
  
  if (((*(byte *)(DAT_00951c4c + 0x4c) < 0x20) && (iVar2 = FUN_004f7fb0(param_1), iVar2 != 0)) &&
     (iVar3 = FUN_005cf5b0(*(undefined4 *)(DAT_00951c60 + 0x13c),
                           (uint)*(byte *)(DAT_00951c4c + 0x4c) * 0x10 +
                           *(int *)(DAT_00951c4c + 0x48),*(undefined4 *)(param_1 + 0x510),1),
     iVar2 = DAT_00951c4c, iVar3 != 0)) {
    pbVar1 = (byte *)((uint)*(byte *)(DAT_00951c4c + 0x4c) * 0x10 + 0xc +
                     *(int *)(DAT_00951c4c + 0x48));
    *pbVar1 = *pbVar1 & 0xfe;
    pbVar1 = (byte *)((uint)*(byte *)(iVar2 + 0x4c) * 0x10 + 0xc + *(int *)(iVar2 + 0x48));
    *pbVar1 = *pbVar1 & 0xfd;
    iVar2 = FUN_004f7fb0(param_1);
    while (iVar2 != 0) {
      iVar3 = FUN_004f8b10(*(undefined4 *)(param_1 + 0x510),&DAT_007622ac);
      iVar2 = DAT_00951c4c;
      if (iVar3 == 0) {
        pbVar1 = (byte *)((uint)*(byte *)(DAT_00951c4c + 0x4c) * 0x10 + 0xc +
                         *(int *)(DAT_00951c4c + 0x48));
        *pbVar1 = *pbVar1 | 1;
        pbVar1 = (byte *)((uint)*(byte *)(iVar2 + 0x4c) * 0x10 + 0xc + *(int *)(iVar2 + 0x48));
        *pbVar1 = *pbVar1 & 0xfd;
      }
      else {
        iVar3 = FUN_004f8b10(*(undefined4 *)(param_1 + 0x510),&DAT_00758e24);
        iVar2 = DAT_00951c4c;
        if (iVar3 == 0) {
          pbVar1 = (byte *)((uint)*(byte *)(DAT_00951c4c + 0x4c) * 0x10 + 0xc +
                           *(int *)(DAT_00951c4c + 0x48));
          *pbVar1 = *pbVar1 & 0xfe;
          pbVar1 = (byte *)((uint)*(byte *)(iVar2 + 0x4c) * 0x10 + 0xc + *(int *)(iVar2 + 0x48));
          *pbVar1 = *pbVar1 | 2;
        }
        else {
          iVar2 = FUN_004f8b10(*(undefined4 *)(param_1 + 0x510),"end_anim");
          if (((iVar2 == 0) ||
              (iVar2 = FUN_004f8b10(*(undefined4 *)(param_1 + 0x510),"endanim"), iVar2 == 0)) ||
             ((iVar2 = FUN_004f8b10(*(undefined4 *)(param_1 + 0x510),"anim_end"), iVar2 == 0 ||
              (iVar2 = FUN_004f8b10(*(undefined4 *)(param_1 + 0x510),"animend"), iVar2 == 0)))) {
            iVar2 = DAT_00951c4c;
            pbVar1 = (byte *)((uint)*(byte *)(DAT_00951c4c + 0x4c) * 0x10 + 0xc +
                             *(int *)(DAT_00951c4c + 0x48));
            *pbVar1 = *pbVar1 & 0xfe;
            pbVar1 = (byte *)((uint)*(byte *)(iVar2 + 0x4c) * 0x10 + 0xc + *(int *)(iVar2 + 0x48));
            *pbVar1 = *pbVar1 & 0xfd;
            pbVar1 = (byte *)((uint)*(byte *)(iVar2 + 0x4c) * 0x10 + 0xc + *(int *)(iVar2 + 0x48));
            *pbVar1 = *pbVar1 | 4;
          }
        }
      }
      iVar2 = FUN_004f7fb0(param_1);
    }
    *(char *)(DAT_00951c4c + 0x4c) = *(char *)(DAT_00951c4c + 0x4c) + '\x01';
  }
  return;
}

