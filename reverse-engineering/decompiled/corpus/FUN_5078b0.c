/* Ghidra analysis pseudocode, not original source.
 * ev_198b3c40c86fc47a34e355c4a7b923cf37494fadf6a0e41ec42e09959f8ec2d3
 * Entry: 0x5078b0; label: FUN_005078b0
 */

void FUN_005078b0(undefined4 param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  byte bVar4;
  undefined4 extraout_ECX;
  int iVar5;
  undefined4 *puVar6;
  int local_34;
  undefined4 local_30;
  int local_2c;
  int local_28;
  char local_24 [32];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_34;
  local_30 = param_1;
  puVar2 = DAT_009212dc;
  do {
    if (puVar2 == (undefined4 *)0x0) {
      __security_check_cookie(local_4 ^ (uint)&local_34);
      return;
    }
    local_28 = puVar2[2];
    local_2c = puVar2[4];
    if (((*(byte *)(puVar2 + 0xe) & 1) == 0) && (iVar5 = 0, 0 < *(int *)(local_28 + 8))) {
      local_34 = 0;
      do {
        puVar6 = (undefined4 *)(*(int *)(local_28 + 0xc) + local_34);
        iVar1 = puVar2[3] + iVar5 * 4;
        if ((*(char *)(puVar2[3] + 2 + iVar5 * 4) == -1) &&
           ((bVar4 = *(byte *)(iVar1 + 3) & 1, bVar4 == 0 || ((*(byte *)(puVar6 + 3) & 4) != 0)))) {
          if (puVar6[1] != 0) {
            if ((puVar6[1] == 1) &&
               ((((*(byte *)(puVar6 + 3) & 8) == 0 || (param_3 != 0)) || (bVar4 != 0)))) {
              if (*(short *)((int)puVar6 + 0x2e) < 0) {
                iVar3 = FUN_00505200(puVar6,param_1,param_2);
              }
              else {
                iVar3 = *(short *)((int)puVar6 + 0x2e) * 0x50 + *(int *)(local_2c + 0x20);
                if ((*(byte *)(iVar3 + 0x44) & 1) == 0) goto LAB_005079d6;
                if (*(int *)(iVar3 + 0x48) == 0) {
                  iVar3 = FUN_00504eb0(puVar6,iVar3,param_1,param_2);
                }
                else {
                  iVar3 = FUN_00504eb0(puVar6,*(int *)(iVar3 + 0x48),param_1,param_2);
                }
              }
              if (iVar3 != 0) goto LAB_005079ab;
            }
            goto LAB_005079d6;
          }
LAB_005079ab:
          if ((*(byte *)(iVar1 + 3) & 1) == 0) {
            FUN_004fff10(*puVar6,*puVar6);
            *(byte *)(iVar1 + 3) = *(byte *)(iVar1 + 3) | 1;
            FUN_00507750(puVar2[5],*puVar6,puVar2[4],puVar2);
          }
        }
        else {
LAB_005079d6:
          if (((*(byte *)(iVar1 + 3) & 1) != 0) && ((*(byte *)(puVar6 + 3) & 4) != 0)) {
            _sprintf(local_24,"reset_%s",*puVar6);
            FUN_004fff10(*puVar6,local_24);
            *(byte *)(iVar1 + 3) = *(byte *)(iVar1 + 3) & 0xfe;
            FUN_00507750(puVar2[5],extraout_ECX,puVar2[4],puVar2);
          }
        }
        local_34 = local_34 + 0x34;
        iVar5 = iVar5 + 1;
        param_1 = local_30;
      } while (iVar5 < *(int *)(local_28 + 8));
    }
    puVar2 = (undefined4 *)*puVar2;
  } while( true );
}

