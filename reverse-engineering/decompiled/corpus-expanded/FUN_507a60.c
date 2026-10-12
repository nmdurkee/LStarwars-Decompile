/* Ghidra pseudocode, not original source.
 * ev_9d34c938d292037f498e462893e532f4f6f058923093d2cacbd29fd836aaae04
 * Entry: 0x507a60; label: FUN_00507a60
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00507a60(undefined4 param_1,undefined4 param_2,short param_3)

{
  short *psVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  int local_14;
  undefined4 local_10;
  int local_c;
  int local_8;
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_14;
  local_10 = param_1;
  puVar2 = DAT_009212dc;
  do {
    if (puVar2 == (undefined4 *)0x0) {
      __security_check_cookie(local_4 ^ (uint)&local_14);
      return;
    }
    local_8 = puVar2[2];
    local_c = puVar2[4];
    if (((*(byte *)(puVar2 + 0xe) & 1) == 0) && (iVar4 = 0, 0 < *(int *)(local_8 + 8))) {
      local_14 = 0;
      do {
        puVar5 = (undefined4 *)(*(int *)(local_8 + 0xc) + local_14);
        psVar1 = (short *)(puVar2[3] + iVar4 * 4);
        if ((((*(byte *)(puVar2[3] + 3 + iVar4 * 4) & 1) == 0) && ((char)psVar1[1] == -1)) &&
           (puVar5[1] == 2)) {
          if (*(short *)((int)puVar5 + 0x2e) < 0) {
            iVar3 = FUN_00505200(puVar5,param_1,param_2);
            if (iVar3 != 0) {
              *psVar1 = *psVar1 + param_3;
              if (*(short *)(puVar5 + 2) <= *psVar1) {
                FUN_004fff10(*puVar5,*puVar5);
                *(byte *)((int)psVar1 + 3) = *(byte *)((int)psVar1 + 3) | 1;
                FUN_00507750(puVar2[5],*puVar5,puVar2[4],puVar2);
              }
              goto LAB_00507b44;
            }
          }
          else {
            iVar3 = *(short *)((int)puVar5 + 0x2e) * 0x50 + *(int *)(local_c + 0x20);
            if ((*(byte *)(iVar3 + 0x44) & 1) != 0) {
              if (*(int *)(iVar3 + 0x48) == 0) {
                iVar3 = FUN_00504eb0(puVar5,iVar3,param_1,param_2);
                if (iVar3 != 0) {
                  *psVar1 = *psVar1 + param_3;
                  goto LAB_00507b2e;
                }
              }
              else {
                iVar3 = FUN_00504eb0(puVar5,*(int *)(iVar3 + 0x48),param_1,param_2);
                if (iVar3 != 0) {
                  *psVar1 = *psVar1 + param_3;
LAB_00507b2e:
                  if (*(short *)(puVar5 + 2) <= *psVar1) {
                    FUN_00507810(puVar2,puVar5,psVar1,1);
                  }
LAB_00507b44:
                  __security_check_cookie(local_4 ^ (uint)&local_14);
                  return;
                }
              }
            }
          }
        }
        local_14 = local_14 + 0x34;
        iVar4 = iVar4 + 1;
        param_1 = local_10;
      } while (iVar4 < *(int *)(local_8 + 8));
    }
    puVar2 = (undefined4 *)*puVar2;
  } while( true );
}

