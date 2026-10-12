/* Ghidra analysis pseudocode, not original source.
 * ev_949d4af3ed5d02dbfb80406f797a2538e9383f6308f9fa8dd86ff8ae723dc597
 * Entry: 0x514640; label: FUN_00514640
 */

void FUN_00514640(undefined4 param_1,undefined4 param_2,int *param_3,int param_4,undefined4 param_5,
                 int param_6,undefined4 param_7,int param_8,int param_9)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  undefined8 uVar8;
  
  piVar2 = param_3;
  iVar7 = 0;
  if (param_3 == (int *)0x0) {
    return;
  }
  param_3[0x14] = param_3[0x14] & 0xfffffffb;
  *(undefined2 *)((int)param_3 + 0xb2) = 0;
  if (param_8 == 0) {
    param_8 = FUN_00513010(param_1,param_5,param_7,1,1);
    param_3[0x31] = 0;
    if (param_8 == 0) goto LAB_0051479a;
  }
  param_3[1] = param_8;
  param_3[4] = 0;
  if (*param_3 == 0) {
    *param_3 = param_8;
  }
  iVar6 = 4;
  if (param_4 == 0) {
    piVar5 = (int *)(param_8 + 0x1c);
    piVar4 = param_3 + 5;
    do {
      *piVar4 = *piVar5;
      piVar5 = piVar5 + 2;
      iVar6 = iVar6 + -1;
      piVar4 = piVar4 + 1;
    } while (iVar6 != 0);
  }
  else {
    piVar5 = param_3 + 5;
    piVar3 = (int *)(param_4 + 100);
    piVar4 = piVar5;
    do {
      iVar1 = *piVar3;
      piVar3 = piVar3 + 1;
      *piVar4 = iVar1;
      piVar4 = piVar4 + 1;
      iVar6 = iVar6 + -1;
    } while (iVar6 != 0);
    param_3 = (int *)(param_8 + 0x1c);
    do {
      uVar8 = __allshl();
      if (((uint)uVar8 & *(uint *)(param_4 + 0x48)) == 0 &&
          ((uint)((ulonglong)uVar8 >> 0x20) & (int)*(uint *)(param_4 + 0x48) >> 0x1f) == 0) {
        *piVar5 = *param_3;
      }
      param_3 = param_3 + 2;
      iVar7 = iVar7 + 1;
      piVar5 = piVar5 + 1;
    } while (iVar7 < 4);
  }
  if ((param_9 == 0) && ((param_6 == 0 || (param_9 = FUN_00512fc0(param_6,param_8), param_9 == 0))))
  {
    if ((piVar2[1] != 0) && (iVar7 = FUN_00512fc0(&DAT_00753270,piVar2[1]), iVar7 != 0)) {
      FUN_005145a0(piVar2,iVar7);
    }
  }
  else {
    if ((piVar2[0x14] & 4U) == 0) {
      *(undefined2 *)((int)piVar2 + 0xb2) = 0;
    }
    piVar2[0x14] = piVar2[0x14] & 0xfffffffb;
    piVar2[2] = param_9;
    piVar2[3] = 0;
    piVar2[4] = 0;
    *(undefined1 *)(piVar2 + 0xe) = 1;
    FUN_00514550();
  }
LAB_0051479a:
  *(undefined1 *)(piVar2 + 0x2d) = 0;
  piVar2[0x2e] = 0;
  *(undefined1 *)((int)piVar2 + 0xb5) = 0;
  piVar2[0x2f] = 0;
  piVar2[0x30] = 0;
  return;
}

