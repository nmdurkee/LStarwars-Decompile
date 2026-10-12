/* Ghidra pseudocode, not original source.
 * ev_a103ceaacd7b90633bbc7eb873f3b3a614efe51f7b7d408a5131b98d70731c28
 * Entry: 0x440290; label: FUN_00440290
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4
FUN_00440290(int param_1,int param_2,float param_3,undefined4 param_4,float param_5,int param_6,
            float param_7,float param_8)

{
  undefined4 uVar1;
  short sVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  float10 fVar6;
  undefined1 local_10c [4];
  float local_108;
  int aiStack_100 [64];
  
  iVar4 = 0;
  if (0x40 < param_2) {
    param_2 = 0x40;
  }
  iVar5 = 0;
  if (0 < param_2) {
    do {
      iVar3 = *(int *)(param_1 + iVar5 * 4);
      if (iVar3 != 0) {
        if (param_6 == 0) {
          if (((param_3 <= 0.0) ||
              (iVar3 = FUN_005d6620(iVar3 + 0x10,param_3,&DAT_00806680), iVar3 != 0)) ||
             ((sVar2 = FUN_005d92b0(*(undefined4 *)(PTR_DAT_00802c54 + 0x13c),
                                    *(int *)(param_1 + iVar5 * 4) + 0x10), -1 < sVar2 &&
              (*(char *)((int)sVar2 + *(int *)(PTR_DAT_00802c54 + 0x2a94)) == '\0'))))
          goto LAB_00440362;
        }
        else {
          iVar3 = FUN_005d6620(iVar3 + 0x10,0,&DAT_00806680);
          if (iVar3 == 0) {
LAB_00440362:
            if (param_5 == 1e+09) {
              aiStack_100[iVar4] = iVar5;
              iVar4 = iVar4 + 1;
            }
            else {
              fVar6 = (float10)FUN_005b3c50(param_4,*(int *)(param_1 + iVar5 * 4) + 0x10,local_10c);
              if (((param_8 == 1e+09) || (param_8 <= local_108)) &&
                 (((param_7 == 1e+09 || (local_108 <= param_7)) &&
                  ((float)fVar6 < param_5 * param_5)))) {
                aiStack_100[iVar4] = iVar5;
                iVar4 = iVar4 + 1;
              }
            }
          }
        }
      }
      iVar5 = iVar5 + 1;
    } while (iVar5 < param_2);
    if (iVar4 != 0) {
      iVar5 = FUN_0054fa60();
      uVar1 = *(undefined4 *)
               (param_1 + aiStack_100[iVar5 / ((int)(0xffff / (longlong)iVar4) + 1)] * 4);
      *(undefined4 *)(param_1 + aiStack_100[iVar5 / ((int)(0xffff / (longlong)iVar4) + 1)] * 4) = 0;
      return uVar1;
    }
  }
  return 0;
}

