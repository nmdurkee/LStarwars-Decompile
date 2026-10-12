/* Ghidra pseudocode, not original source.
 * ev_9d34c938d292037f498e462893e532f4f6f058923093d2cacbd29fd836aaae04
 * Entry: 0x507f20; label: FUN_00507f20
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00507f20(int param_1,undefined4 param_2,undefined4 param_3)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  char local_59;
  int local_58;
  int local_54;
  int *local_50;
  int local_4c;
  int *local_48;
  int local_44;
  undefined1 local_40 [64];
  
  local_44 = *(int *)(param_1 + 0x58);
  piVar4 = *(int **)(local_44 + 0x14);
  local_48 = *(int **)(param_1 + 0xa0);
  local_4c = 0;
  if ((short)piVar4[1] != 0) {
    local_54 = 0;
    local_58 = 0;
    local_50 = piVar4;
    do {
      iVar5 = *piVar4 + local_58;
      iVar6 = *local_48 + local_54;
      if (((*(byte *)(iVar5 + 0x58) & 2) != 0) && ((*(byte *)(iVar5 + 0x58) & 4) != 0)) {
        if ((*(int *)(iVar5 + 0x50) != 0) &&
           (iVar3 = FUN_005da520(*(int *)(iVar5 + 0x50),iVar6 + 0xc,&local_59,param_2), iVar3 != 0))
        {
          *(bool *)(iVar6 + 0xd) = local_59 != '\0';
        }
        if (*(char *)(iVar6 + 0xd) != '\0') {
          FUN_00502390(iVar5,param_2,local_40);
          if ((*(byte *)(param_1 + 0x88) & 0x80) != 0) {
            FUN_005b5430(local_40,local_40,param_1 + 0x18);
          }
          if (*(float *)(param_1 + 0xe8) == 1.0) {
            FUN_005f33b0(iVar6,local_40);
          }
          else {
            FUN_005ff7a0(iVar6,local_40,*(undefined4 *)(param_1 + 0xe8));
          }
          if ((DAT_009213b0 != (code *)0x0) && ((*(byte *)(iVar5 + 0x58) & 0x18) != 0)) {
            (*DAT_009213b0)(iVar5,iVar6,local_40);
          }
          if (DAT_009213ac != (code *)0x0) {
            (*DAT_009213ac)(iVar5,local_40);
          }
          if (*(char *)(iVar5 + 0x5a) != -1) {
            piVar1 = *(int **)(local_44 + 0x1c);
            piVar2 = *(int **)(param_1 + 0xa8);
            iVar6 = 0;
            piVar4 = local_50;
            if (*(char *)(iVar5 + 0x59) != '\0') {
              do {
                iVar3 = (uint)*(byte *)(iVar5 + 0x5a) + iVar6;
                FUN_00507c50(param_1,piVar1,*piVar2 + iVar3 * 8,iVar3 * 100 + *piVar1,param_2,
                             local_40,param_3);
                iVar6 = iVar6 + 1;
                piVar4 = local_50;
              } while (iVar6 < (int)(uint)*(byte *)(iVar5 + 0x59));
            }
          }
        }
      }
      local_58 = local_58 + 0x5c;
      local_54 = local_54 + 0x10;
      local_4c = local_4c + 1;
    } while (local_4c < (int)(uint)*(ushort *)(piVar4 + 1));
  }
  return;
}

