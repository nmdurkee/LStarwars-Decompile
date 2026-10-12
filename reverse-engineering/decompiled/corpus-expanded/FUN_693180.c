/* Ghidra pseudocode, not original source.
 * ev_afaf96d8212bac568eff783f147ec9070d27632600cf266ffbce68fe899dcf72
 * Entry: 0x693180; label: FUN_00693180
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_00693180(int param_1)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  local_14 = 0x80404040;
  local_4 = 0x80404040;
  local_20 = 0x80000000;
  local_1c = 0x80ff0000;
  local_18 = 0x80808080;
  local_10 = 0x80303030;
  local_c = 0x80ff0000;
  local_8 = 0x80808080;
  if (DAT_029231a8 == -1) {
    return;
  }
  if ((&DAT_02924b60)[DAT_029231a8 * 0x16] == -1) {
    return;
  }
  iVar2 = *(int *)(DAT_0296209c +
                  *(short *)((&DAT_02924b60)[DAT_029231a8 * 0x16] * 0x330 + 0x182 + DAT_029620a4) *
                  4);
  DAT_02961fac = FUN_00619250(0x46,0x46,0xfa,300,DAT_02912e80,FUN_0066acb0,"Emitter Settings");
  if (DAT_02961fac == 0) goto LAB_006934ba;
  uVar3 = FUN_00627a80(1,&local_20,0,0,FUN_00668f70,"Emitter Vel...");
  FUN_00618e10(DAT_02961fac,uVar3);
  uVar3 = FUN_00627a80(1,&local_20,0,0,FUN_006690c0,"Gravity...");
  FUN_00618e10(DAT_02961fac,uVar3);
  cVar1 = *(char *)(iVar2 + 0x2c);
  if ((((cVar1 == '\0') || (cVar1 == '\b')) || (cVar1 == '\t')) || (cVar1 == '\n')) {
    uVar3 = FUN_00627a80(1,&local_20,0,0,FUN_00667de0,"Random Start...");
LAB_006932e2:
    FUN_00618e10(DAT_02961fac,uVar3);
  }
  else if (((cVar1 == '\x06') || (cVar1 == '\a')) || ((cVar1 == '\v' || (cVar1 == '\f')))) {
    uVar3 = FUN_00627a80(1,&local_20,0,0,FUN_00667de0,"Base Emit Vector...");
    goto LAB_006932e2;
  }
  cVar1 = *(char *)(iVar2 + 0x2c);
  if (cVar1 == '\0') {
    uVar3 = FUN_00627a80(1,&local_20,0,0,FUN_00668320,"Start Velocity...");
LAB_0069333f:
    FUN_00618e10(DAT_02961fac,uVar3);
  }
  else if ((cVar1 == '\a') || (cVar1 == '\v')) {
    uVar3 = FUN_00627a80(1,&local_20,0,0,FUN_00668320,"Emit Point Velocity...");
    goto LAB_0069333f;
  }
  uVar3 = FUN_00627a80(1,&local_20,0,0,FUN_006677f0,"Emitter Variation...");
  FUN_00618e10(DAT_02961fac,uVar3);
  uVar3 = FUN_00627a80(1,&local_20,0,0,FUN_0068d170,"Particles per Sec...");
  FUN_00618e10(DAT_02961fac,uVar3);
  uVar3 = FUN_00627a80(1,&local_20,0,0,FUN_0068d2c0,"Particle Life...");
  FUN_00618e10(DAT_02961fac,uVar3);
  uVar3 = FUN_00627a80(1,&local_20,0,0,FUN_0068dd10,"Emitter Timing...");
  FUN_00618e10(DAT_02961fac,uVar3);
  uVar3 = FUN_00627a80(1,&local_20,0,0,FUN_00667540,"Repeat / Radii...");
  FUN_00618e10(DAT_02961fac,uVar3);
  cVar1 = *(char *)(iVar2 + 0x2c);
  if ((((cVar1 == '\0') || (cVar1 == '\x06')) || (cVar1 == '\a')) || (cVar1 == '\b')) {
    uVar3 = FUN_00627a80(1,&local_20,0,0,&LAB_00692a50,"Particle Ghosts...");
  }
  else {
    uVar3 = FUN_00627a80(1,&local_10,0,0,0,"Particle Ghosts...");
  }
  FUN_00618e10(DAT_02961fac,uVar3);
  if (*(char *)(iVar2 + 0x2c) == '\f') {
    uVar3 = FUN_00627a80(1,&local_20,0,0,FUN_00665040,"Star Settings...");
  }
  else {
    uVar3 = FUN_00627a80(1,&local_10,0,0,0,"Star Settings...");
  }
  FUN_00618e10(DAT_02961fac,uVar3);
LAB_006934ba:
  FUN_006279b0(param_1,DAT_02961fac);
  *(int *)(DAT_02961fac + 0x14) = *(int *)(param_1 + 0x14) + 10;
  *(int *)(DAT_02961fac + 0x18) = *(int *)(param_1 + 0x18) + 0x28;
  return;
}

