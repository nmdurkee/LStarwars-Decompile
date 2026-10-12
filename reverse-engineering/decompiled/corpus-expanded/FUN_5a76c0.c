/* Ghidra pseudocode, not original source.
 * ev_ab3200993c06f50ca9adf40c5a4b161cdaf830edaeb783e0e0f7b7da1276ea12
 * Entry: 0x5a76c0; label: FUN_005a76c0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_005a76c0(int param_1,int param_2,int param_3)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  float local_c [2];
  float local_4;
  
  if ((param_2 != 0) && (iVar4 = 0, 0 < *(int *)(param_1 + 0x46c0))) {
    do {
      uVar1 = *(uint *)(param_2 + 200);
      if (((uVar1 & 0x40000) != 0) && (((uVar1 & 0x1000000) != 0 && ((uVar1 & 0x2000000) == 0)))) {
        uVar2 = FUN_005cffb0(param_2 + 0x24);
        iVar3 = FUN_0067c760(uVar2);
        if ((iVar3 != -1) && (iVar3 == *(short *)(param_3 + 0xfa))) {
          if (*(int *)(param_3 + 4) != 0) {
            FUN_005b3800(local_c,*(int *)(param_3 + 4) + 0x80,*(undefined4 *)(param_2 + 0x58));
            if (local_4 == local_c[0]) {
              if (0.0 <= local_c[0]) {
                iVar4 = FUN_0054fa60();
                local_c[0] = (float)iVar4 * 1.5259022e-05;
                iVar4 = FUN_0054fa60();
                local_4 = (float)iVar4 * 1.5259022e-05;
              }
              else {
                iVar4 = FUN_0054fa60();
                local_c[0] = -((float)iVar4 * 1.5259022e-05);
                iVar4 = FUN_0054fa60();
                local_4 = -((float)iVar4 * 1.5259022e-05);
              }
            }
            if (ABS(local_c[0]) <= ABS(local_4)) {
              local_c[0] = 0.0;
            }
            else {
              local_4 = 0.0;
            }
            FUN_005b3b30(local_c,local_c);
            FUN_005a4400(param_2,local_c);
          }
          return 1;
        }
      }
      iVar4 = iVar4 + 1;
      param_2 = param_2 + 0xd4;
    } while (iVar4 < *(int *)(param_1 + 0x46c0));
  }
  return 0;
}

