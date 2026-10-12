/* Ghidra pseudocode, not original source.
 * ev_07ae9e2e04489686a5b927c1fa0593b6d570aedc464c7aee9c2d2b7a39d3047e
 * Entry: 0x429210; label: FUN_00429210
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_00429210(int param_1,int param_2,int param_3)

{
  int iVar1;
  short *psVar2;
  int iVar3;
  undefined4 uVar4;
  
  if (*(int *)(param_1 + 0xcbc) != 0) {
    iVar1 = FUN_004cc920(*(int *)(param_1 + 0xcbc));
    psVar2 = &DAT_007fcfcc + iVar1 * 0xc;
    iVar3 = iVar1;
    do {
      if (param_2 == 0) {
        iVar3 = iVar3 + 1;
        psVar2 = psVar2 + 0xc;
      }
      else {
        iVar3 = iVar3 + -1;
        psVar2 = psVar2 + -0xc;
      }
      if (iVar3 < 0) {
        return 0;
      }
      if (iVar3 == 10) {
        return 0;
      }
      if (*psVar2 != *(short *)(param_1 + 0x1064)) {
        return 0;
      }
      if (iVar3 == iVar1) {
        return 0;
      }
    } while ((DAT_0087aa8c & 1 << ((byte)iVar3 & 0x1f)) == 0);
    if (iVar3 != -1) {
      FUN_0041bc20(param_1,(int)*(short *)(param_1 + 0x1064),0xffffffff,1);
      if (param_3 != 0) {
        if (param_2 == 0) {
          uVar4 = 0x24;
        }
        else {
          uVar4 = 0x23;
        }
        FUN_00547930(uVar4,param_1 + 0x80,0,0);
      }
      *(undefined ***)(param_1 + 0xcbc) = &PTR_s_batman_007fcfb8 + iVar3 * 6;
      FUN_0041b0a0(param_1);
      return 1;
    }
  }
  return 0;
}

