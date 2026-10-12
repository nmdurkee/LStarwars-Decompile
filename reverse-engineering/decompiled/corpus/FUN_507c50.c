/* Ghidra analysis pseudocode, not original source.
 * ev_198b3c40c86fc47a34e355c4a7b923cf37494fadf6a0e41ec42e09959f8ec2d3
 * Entry: 0x507c50; label: FUN_00507c50
 */

void FUN_00507c50(int param_1,int param_2,undefined4 param_3,int param_4,undefined4 param_5,
                 undefined4 param_6,int param_7)

{
  int iVar1;
  byte bVar2;
  ushort uVar3;
  code *pcVar4;
  
  iVar1 = *(int *)(param_2 + 4) + (uint)*(byte *)(param_4 + 0x59) * 0xc;
  bVar2 = *(byte *)(iVar1 + 4);
  if ((bVar2 & 1) == 0) {
    if ((bVar2 & 2) == 0) {
      if ((bVar2 & 0x10) == 0) {
        if ((bVar2 & 4) == 0) {
          if (((bVar2 & 8) != 0) && (param_7 == 0)) {
            FUN_00506e40(param_4,param_5,param_6,param_1);
          }
        }
        else if ((DAT_009213b8 != (code *)0x0) && (*(float *)(param_1 + 0x98) != 0.0)) {
          (*DAT_009213b8)(param_2,param_3,param_4,param_5,param_6,param_7);
          return;
        }
      }
      else if (param_7 == 0) {
        FUN_00501d40(param_3,param_5,param_6);
        return;
      }
    }
    else {
      uVar3 = *(ushort *)(iVar1 + 6);
      if ((uVar3 != 0xffff) &&
         (pcVar4 = *(code **)(DAT_009213c0 + 0x10 + (uint)uVar3 * 0x14), pcVar4 != (code *)0x0)) {
        (*pcVar4)(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
        return;
      }
    }
  }
  else if (param_7 == 0) {
    FUN_00501a80(param_3,param_5,param_6);
    return;
  }
  return;
}

