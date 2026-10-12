/* Ghidra analysis pseudocode, not original source.
 * ev_726a28db9a436487e0129f186879c1991782c0ddc180f98bd984abea004253e2
 * Entry: 0x57e430; label: FUN_0057e430
 */

void FUN_0057e430(undefined4 param_1,uint *param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8)

{
  short *psVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  short local_24 [2];
  uint local_20;
  undefined4 local_1c;
  ushort local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  iVar3 = FUN_004fc860(param_1);
  if (iVar3 == 0) {
    FUN_0057a820(param_1);
    return;
  }
  local_20 = *param_2 + 3 & 0xfffffffc;
  *param_2 = local_20;
  local_1c = 0;
  local_18 = 0;
  local_14 = param_4;
  local_10 = param_5;
  local_c = param_6;
  local_8 = param_7;
  local_4 = param_8;
  iVar4 = FUN_004fc5b0(iVar3);
  while (iVar4 != 0) {
    iVar4 = FUN_004f7fb0(iVar3);
    if ((iVar4 != 0) &&
       (iVar4 = FUN_004f8b10(*(undefined4 *)(iVar3 + 0x510),&DAT_007625fc), iVar4 == 0)) {
      psVar1 = (short *)(local_20 + (uint)local_18 * 0x44);
      *psVar1 = -1;
      *(undefined1 *)(psVar1 + 1) = 0;
      *(undefined1 *)(psVar1 + 2) = 0;
      iVar4 = FUN_004f7fb0(iVar3);
      while (iVar4 != 0) {
        iVar4 = FUN_004f8b10(*(undefined4 *)(iVar3 + 0x510),"in_level");
        if (iVar4 == 0) {
          iVar4 = FUN_004f7fb0(iVar3);
          if (iVar4 != 0) {
            iVar4 = FUN_00578da0(*(undefined4 *)(iVar3 + 0x510),local_24);
            if (iVar4 == 0) {
              FUN_0057a820(*(undefined4 *)(iVar3 + 0x510));
            }
            else {
              *psVar1 = local_24[0];
            }
          }
        }
        else {
          iVar4 = FUN_004f8b10(*(undefined4 *)(iVar3 + 0x510),&DAT_0075782c);
          if (iVar4 == 0) {
            iVar4 = FUN_004f7fb0(iVar3);
            if ((iVar4 != 0) && (iVar4 = FUN_004f1ff0(*(undefined4 *)(iVar3 + 0x510)), iVar4 < 0x40)
               ) {
              FUN_004f1f10(psVar1 + 2,*(undefined4 *)(iVar3 + 0x510));
            }
          }
          else {
            iVar4 = FUN_004f8b10(*(undefined4 *)(iVar3 + 0x510),"intro");
            if (iVar4 == 0) {
              *(undefined1 *)(psVar1 + 1) = 0;
            }
            else {
              iVar4 = FUN_004f8b10(*(undefined4 *)(iVar3 + 0x510),"midtro");
              if (iVar4 == 0) {
                *(undefined1 *)(psVar1 + 1) = 1;
              }
              else {
                iVar4 = FUN_004f8b10(*(undefined4 *)(iVar3 + 0x510),"outro");
                if (iVar4 == 0) {
                  *(undefined1 *)(psVar1 + 1) = 2;
                }
                else {
                  iVar4 = FUN_004f8b10(*(undefined4 *)(iVar3 + 0x510),"ending");
                  if (iVar4 == 0) {
                    *(undefined1 *)(psVar1 + 1) = 3;
                  }
                }
              }
            }
          }
        }
        iVar4 = FUN_004f7fb0(iVar3);
      }
      if ((*psVar1 != -1) &&
         ((DAT_00951cb4 == (code *)0x0 || (iVar4 = (*DAT_00951cb4)(psVar1), iVar4 != 0)))) {
        local_18 = local_18 + 1;
      }
    }
    iVar4 = FUN_004fc5b0(iVar3);
  }
  FUN_004fa300(iVar3);
  if (local_18 == 0) {
    FUN_0057a820(param_1);
    return;
  }
  uVar2 = local_20 + (uint)local_18 * 0x44;
  *param_2 = uVar2;
  FUN_004ef660(uVar2,&local_20,0x20);
  DAT_00951cb0 = *param_2;
  *param_2 = *param_2 + 0x20;
  return;
}

