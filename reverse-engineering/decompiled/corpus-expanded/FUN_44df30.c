/* Ghidra pseudocode, not original source.
 * ev_89fddb9d43176fe460e635fa694f7b202ecc9b6cc52422bc9fe5e2fbe10c5c63
 * Entry: 0x44df30; label: FUN_0044df30
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4
FUN_0044df30(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4,int param_5,
            int param_6)

{
  bool bVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  float10 fVar6;
  int local_14;
  undefined4 local_10;
  int local_8;
  float local_4;
  
  local_4 = 0.0;
  iVar5 = 0;
  iVar4 = 0;
  bVar1 = false;
  local_14 = 0;
  local_10 = 0;
  local_8 = 0;
  if ((param_6 != 0) && (0 < param_5)) {
    do {
      iVar2 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar5 * 4),"pathname=");
      if (iVar2 == 0) {
        iVar2 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar5 * 4),"bothways");
        if (iVar2 == 0) {
          iVar2 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar5 * 4),"from=");
          if (iVar2 == 0) {
            iVar2 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar5 * 4),&DAT_00757c50);
            if (iVar2 == 0) {
              iVar2 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar5 * 4),"jump_off_dy=");
              if (iVar2 == 0) {
                iVar2 = FUN_004f8a70(*(undefined4 *)(param_4 + iVar5 * 4),"grapple=");
                if ((iVar2 != 0) &&
                   (piVar3 = (int *)FUN_0055a020(*(undefined4 *)(PTR_DAT_00802c54 + 0x2ac8),
                                                 DAT_00802460,iVar2 + 8), piVar3 != (int *)0x0)) {
                  local_8 = *piVar3;
                }
              }
              else {
                fVar6 = (float10)FUN_005147c0(param_2,iVar2 + 0xc);
                local_4 = (float)fVar6;
              }
            }
            else {
              iVar4 = iVar2 + 3;
            }
          }
          else {
            local_14 = iVar2 + 5;
          }
        }
        else {
          bVar1 = true;
        }
      }
      else {
        local_10 = FUN_0051ad20(param_1,iVar2 + 9);
      }
      iVar5 = iVar5 + 1;
    } while (iVar5 < param_5);
    if (((local_14 != 0) && (iVar4 != 0)) &&
       (iVar4 = FUN_0051adf0(param_1,local_10,local_14,iVar4,&param_6), iVar4 != 0)) {
      if (bVar1) {
        param_6 = 0xff;
      }
      if ((local_8 != 0) &&
         (iVar4 = FUN_005ab140(*(undefined4 *)(PTR_DAT_00802c54 + 0x4674),iVar4,param_6,local_8,1),
         iVar4 != 0)) {
        *(float *)(iVar4 + 0xc) = local_4;
      }
    }
    return 1;
  }
  return 1;
}

