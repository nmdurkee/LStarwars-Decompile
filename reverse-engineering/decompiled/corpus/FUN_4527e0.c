/* Ghidra analysis pseudocode, not original source.
 * ev_967bc49bfb89c9289ebafb6996ca9c72d569b4a48639dbecd20a21d28d62ec51
 * Entry: 0x4527e0; label: FUN_004527e0
 */

undefined4
FUN_004527e0(undefined4 param_1,int param_2,int param_3,int param_4,int param_5,int param_6)

{
  int *piVar1;
  int iVar2;
  bool bVar3;
  int iVar4;
  uint uVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  int local_20;
  int local_1c;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  iVar8 = 0;
  bVar3 = false;
  local_1c = 0;
  local_20 = 0;
  if (DAT_0093d810 == 0) {
    return 0;
  }
  if (((param_3 != 0) && (piVar1 = *(int **)(param_3 + 0xd0), piVar1 != (int *)0x0)) &&
     (*piVar1 != 0)) {
    iVar2 = *piVar1;
    if (param_6 != 0) {
      iVar7 = 0;
      *(float *)(param_2 + 0x70) = (float)*(ushort *)(iVar2 + 0x27a);
      if (0 < param_5) {
        do {
          if ((DAT_009238b0 == (code *)0x0) ||
             (iVar4 = (*DAT_009238b0)(*(undefined4 *)(param_4 + iVar8 * 4),param_3 + 0x13f),
             iVar4 == 0)) {
            iVar4 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar8 * 4),"min_turn");
            if (iVar4 == 0) {
              iVar4 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar8 * 4),"max_turn");
              if (iVar4 == 0) {
                iVar4 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar8 * 4),"rand_turn_dir");
                if (iVar4 == 0) {
                  iVar4 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar8 * 4),&DAT_0075823c);
                  if (iVar4 != 0) {
                    FUN_005147c0(param_2,iVar4 + 5);
                    FUN_006e6b90();
                    iVar7 = FUN_006e6b90();
                  }
                }
                else {
                  bVar3 = true;
                }
              }
              else {
                FUN_005147c0(param_2,iVar4 + 9);
                FUN_006e6b90();
                local_20 = FUN_006e6b90();
              }
            }
            else {
              FUN_005147c0(param_2,iVar4 + 9);
              FUN_006e6b90();
              local_1c = FUN_006e6b90();
            }
          }
          iVar8 = iVar8 + 1;
        } while (iVar8 < param_5);
        if (local_20 != 0) {
          FUN_005b9dd0();
          iVar7 = FUN_006e6b90();
          iVar7 = iVar7 + local_1c;
        }
        if (iVar7 != 0) {
          if ((bVar3) && (uVar5 = FUN_005b9e90(0), (uVar5 & 1) != 0)) {
            iVar7 = -iVar7;
          }
          uVar6 = FUN_006e6b90(iVar7);
          iVar8 = FUN_005be590(uVar6);
          *(float *)(param_2 + 0x70) = (float)iVar8;
        }
      }
    }
    if ((*(byte *)(param_3 + 0x166) & 1) != 0) {
      local_c = 0;
      local_8 = 0;
      local_4 = 0x41200000;
      uVar6 = FUN_006e6b90();
      FUN_005b3620(&local_c,&local_c,uVar6);
      FUN_005b37d0(&local_c,&local_c,iVar2 + 0x5c);
      FUN_0052fcb0(param_3,&local_c,0,param_3 + 0x158,1,0x3c23d70a);
    }
    return 0;
  }
  return 0;
}

