/* Ghidra pseudocode, not original source.
 * ev_e7751f4f01b1073429001044a4e8501ad85e4023b91c3e954e91fa81cbba79ed
 * Entry: 0x42dca0; label: FUN_0042dca0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_0042dca0(int param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  float10 fVar2;
  
  if (param_2 != 0) {
    if ((DAT_00876584 != 0) && (param_3 != 0)) {
      if (*(int *)(PTR_DAT_00802c54 + 0x128) == DAT_0087b0e0) {
        uVar1 = 0x3e800000;
      }
      else {
        uVar1 = 0x3f000000;
      }
      FUN_005b3830(param_3,param_2 + 0xf18,uVar1);
      fVar2 = (float10)FUN_005bec80(param_3);
      *(float *)(param_1 + 0xcc) = (float)(fVar2 + (float10)*(float *)(param_1 + 0xcc));
      return 0;
    }
    if (((*(int *)(PTR_DAT_00802c54 + 0x128) == DAT_0087b234) &&
        (*(short *)(param_2 + 0x1064) == DAT_007f1948)) ||
       (*(int *)(PTR_DAT_00802c54 + 0x128) == DAT_0087b1d4)) {
      return 1;
    }
  }
  return 0;
}

