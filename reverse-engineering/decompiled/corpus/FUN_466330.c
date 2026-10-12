/* Ghidra analysis pseudocode, not original source.
 * ev_ca54e982c9f1bc50e375bb5e2806226defe8bc9769d9e20e94a8e2507c387560
 * Entry: 0x466330; label: FUN_00466330
 */

void FUN_00466330(int param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  undefined1 local_c [12];
  
  if (param_2 != (int *)0x0) {
    if ((*(byte *)(param_2 + 3) & 1) != 0) {
      FUN_004660b0(param_2,param_2[4]);
      *(ushort *)(param_2 + 3) = *(ushort *)(param_2 + 3) & 0xfffe;
    }
    iVar2 = 0;
    if ((short)param_2[1] != 0) {
      piVar3 = (int *)(*param_2 + 0x1c);
      do {
        if ((((*(ushort *)((int)piVar3 + 0xe) & 2) != 0) &&
            ((*(ushort *)((int)piVar3 + 0xe) & 1) != 0)) && (iVar1 = *piVar3, iVar1 != 0)) {
          if (piVar3[2] == 0) {
            FUN_005a1030(iVar1,0x3f800000,1);
            if ((*(int *)(*piVar3 + 0xc) == 2) &&
               (FUN_005a0b00(*piVar3,local_c,2,1,1), DAT_00951b50 == 0)) {
              iVar1 = FUN_0043d890((int)DAT_007f191c,local_c,0,"dragbomb",0,0,1,0,0,0,0);
              piVar3[2] = iVar1;
              iVar1 = FUN_0056e160(5);
              if (iVar1 != 0) {
                FUN_0062c560(*(undefined4 *)(param_1 + 0x134),0x7d,local_c);
                FUN_0062c560(*(undefined4 *)(param_1 + 0x134),0x7e,local_c);
              }
            }
          }
          else {
            FUN_005a15e0(iVar1,0);
            if ((*(char *)(piVar3[2] + 0x28b) != '\0') ||
               ((*(uint *)(piVar3[2] + 0x1fc) & 0x1000) == 0)) {
              piVar3[2] = 0;
              FUN_005a0fb0(*piVar3);
              FUN_005a1610(*piVar3);
              FUN_005a15e0(*piVar3,1);
            }
          }
        }
        iVar2 = iVar2 + 1;
        piVar3 = piVar3 + 0xb;
      } while (iVar2 < (int)(uint)*(ushort *)(param_2 + 1));
    }
  }
  DAT_00876df4 = 0;
  if ((((DAT_0093d7f0 != 0) && (*(int *)(DAT_0093d7f0 + 0x1040) != 0)) &&
      (iVar2 = *(int *)(*(int *)(DAT_0093d7f0 + 0x1040) + 4), iVar2 != 0)) &&
     (*(short *)(iVar2 + 0x1064) == DAT_007f191c)) {
    DAT_00876df4 = iVar2;
  }
  DAT_00876df8 = 0;
  if (((DAT_0093d7f4 != 0) && (*(int *)(DAT_0093d7f4 + 0x1040) != 0)) &&
     ((iVar2 = *(int *)(*(int *)(DAT_0093d7f4 + 0x1040) + 4), iVar2 != 0 &&
      (*(short *)(iVar2 + 0x1064) == DAT_007f191c)))) {
    DAT_00876df8 = iVar2;
  }
  return;
}

