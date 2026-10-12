/* Ghidra pseudocode, not original source.
 * ev_d21561abf9cd5233ed14ae59a5314f19a5c253e33bc7c4e30ba499fb63508ecc
 * Entry: 0x5fbb50; label: FUN_005fbb50
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_005fbb50(int *param_1,int param_2)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  undefined1 local_4 [4];
  
  piVar2 = param_1;
  param_1[5] = 0;
  FUN_006e4810(param_2 * 0x50,0x208,0,0,param_1 + 5);
  iVar4 = *piVar2;
  if (iVar4 == 0) {
    iVar4 = 5;
  }
  else {
    iVar4 = *(int *)(*(int *)(iVar4 + 0xc) + -0x60 + *(int *)(iVar4 + 4) * 0x78);
  }
  piVar1 = piVar2 + 6;
  iVar3 = iVar4 * 2 + 2;
  FUN_006e4810(iVar3 * 0x10,0,0,0,piVar1);
  param_1 = (int *)0x0;
  FUN_006e5b90(0,0,&param_1,0,*piVar1);
  uVar6 = 0;
  if (0 < iVar3) {
    iVar5 = 0;
    do {
      *(float *)(iVar5 + (int)param_1) = (float)(int)(uVar6 - 1) / (float)(iVar4 * 2 + -1);
      if (*(float *)(iVar5 + (int)param_1) < 0.0) {
        *(undefined4 *)(iVar5 + (int)param_1) = 0;
      }
      if (1.0 < *(float *)(iVar5 + (int)param_1)) {
        *(undefined4 *)(iVar5 + (int)param_1) = 0x3f800000;
      }
      if ((uVar6 & 1) == 0) {
        param_2 = 0x3f000000;
      }
      else {
        param_2 = -0x41000000;
      }
      uVar6 = uVar6 + 1;
      *(int *)(iVar5 + 4 + (int)param_1) = param_2;
      iVar5 = iVar5 + 0x10;
    } while ((int)uVar6 < iVar3);
  }
  FUN_006e5bc0(*piVar1);
  piVar2 = piVar2 + 7;
  FUN_006e46f0(iVar3 * 2,0,0x65,0,piVar2,0);
  iVar5 = 0;
  (**(code **)(*(int *)*piVar2 + 0x2c))((int *)*piVar2,0,0,local_4);
  iVar4 = 0;
  if (0 < iVar3) {
    do {
      *(short *)(iVar5 + iVar4 * 2) = (short)iVar4;
      iVar4 = iVar4 + 1;
    } while (iVar4 < iVar3);
  }
  (**(code **)(*(int *)*piVar2 + 0x30))((int *)*piVar2);
  return 1;
}

