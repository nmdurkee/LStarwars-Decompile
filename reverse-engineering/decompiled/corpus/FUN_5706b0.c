/* Ghidra analysis pseudocode, not original source.
 * ev_f7d91f236b6f78f4ea8add50dcf127a99c92e4ff6e0b09a45204423ea42edd2e
 * Entry: 0x5706b0; label: FUN_005706b0
 */

void FUN_005706b0(int *param_1,float *param_2,undefined4 param_3)

{
  float fVar1;
  float fVar2;
  bool bVar3;
  undefined *puVar4;
  int iVar5;
  undefined4 uVar6;
  int *piVar7;
  float10 fVar8;
  float local_c;
  float local_8;
  float local_4;
  
  local_c = *param_2;
  fVar1 = 1e+09;
  local_8 = param_2[1];
  local_4 = param_2[2];
  bVar3 = false;
  if (*(char *)((int)param_1 + 0xfb) != '\0') {
    FUN_005b37b0(&local_c,&local_c);
    bVar3 = true;
    if (0.0 <= local_c) {
      local_c = 0.825;
    }
    else {
      local_c = -0.825;
    }
    if (0.0 <= local_8) {
      local_8 = 0.825;
    }
    else {
      local_8 = -0.825;
    }
  }
  if (NAN(local_c) || 0.825 < local_c == (local_c == 0.825)) {
    if (local_c <= -0.825) {
      fVar1 = -0.825 - local_c;
      bVar3 = true;
      local_c = -0.825;
      FUN_004f1f10(param_1 + 1,&DAT_007533c8);
    }
  }
  else {
    fVar1 = local_c - 0.825;
    bVar3 = true;
    local_c = 0.825;
    FUN_004f1f10(param_1 + 1,&DAT_007533c4);
  }
  if (local_8 < 0.825) {
    if (local_8 < -0.825 != (local_8 == -0.825)) {
      fVar2 = -0.825 - local_8;
      local_8 = -0.825;
      if ((!bVar3) || ((fVar1 != 1e+09 && (fVar1 < fVar2)))) {
        bVar3 = true;
        puVar4 = DAT_00926c28;
        if (DAT_00926c28 == (undefined *)0x0) {
          puVar4 = &DAT_00755ba8;
        }
        FUN_004f1f10(param_1 + 1,puVar4);
      }
    }
  }
  else {
    fVar2 = local_8 - 0.825;
    local_8 = 0.825;
    if ((!bVar3) || ((fVar1 != 1e+09 && (fVar1 < fVar2)))) {
      bVar3 = true;
      puVar4 = DAT_00926c24;
      if (DAT_00926c24 == (undefined *)0x0) {
        puVar4 = &DAT_00755ba8;
      }
      FUN_004f1f10(param_1 + 1,puVar4);
    }
  }
  fVar8 = (float10)FUN_005becc0(param_1 + 0x25,PTR_DAT_008021b4 + 0x11c,0);
  iVar5 = FUN_0055f450();
  fVar1 = (float)fVar8 / (float)*(byte *)(*(int *)(iVar5 + 0x128) + 0xcd);
  if (fVar1 <= 1.0) {
    if (fVar1 < 0.25) {
      uVar6 = 0x80;
      goto LAB_00570939;
    }
    if (fVar1 < 0.75) {
      uVar6 = FUN_006e6b90();
      goto LAB_00570939;
    }
  }
  uVar6 = 0x40;
LAB_00570939:
  if (bVar3) {
    *(undefined1 *)(param_1 + 0x3d) = 0xff;
    if (*(char *)((int)param_1 + 0xfb) == '\0') {
      *(undefined1 *)((int)param_1 + 0xf6) = 0xff;
      *(undefined1 *)((int)param_1 + 0xf5) = 0xff;
      *(undefined1 *)(param_1 + 0x3f) = 0;
    }
    else {
      *(undefined1 *)((int)param_1 + 0xf6) = 0;
      *(undefined1 *)((int)param_1 + 0xf5) = 0;
      *(undefined1 *)(param_1 + 0x3f) = 0;
    }
  }
  else {
    *(undefined1 *)(param_1 + 0x3d) = 0;
    *(undefined1 *)((int)param_1 + 0xf5) = 0xff;
    *(undefined1 *)((int)param_1 + 0xf6) = 0;
    *(undefined1 *)(param_1 + 0x3f) = 4;
  }
  piVar7 = (int *)*param_1;
  *(char *)((int)param_1 + 0xf7) = (char)uVar6;
  if (piVar7 == (int *)0x0) {
    piVar7 = param_1 + 1;
  }
  FUN_0050c780(piVar7,local_c,local_8,local_4,param_3,param_3,param_3,(char)param_1[0x3f],
               (char)param_1[0x3d],*(undefined1 *)((int)param_1 + 0xf5),
               *(undefined1 *)((int)param_1 + 0xf6),uVar6);
  return;
}

