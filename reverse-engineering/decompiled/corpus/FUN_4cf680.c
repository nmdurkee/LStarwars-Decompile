/* Ghidra analysis pseudocode, not original source.
 * ev_9ea77467f72f0a730098339cc8760ef11d2ea4126d873e77c8bb761228bbcc9d
 * Entry: 0x4cf680; label: FUN_004cf680
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004cf680(int param_1)

{
  char cVar1;
  float fVar2;
  uint uVar3;
  int iVar4;
  char *pcVar5;
  float fStack_c;
  float fStack_8;
  float fStack_4;
  
  if (((*(uint *)(param_1 + 0x144) & 0x8000) != 0) ||
     (cVar1 = *(char *)(param_1 + 0x209), cVar1 == '\x1c')) {
    FUN_0064ac90(param_1,0);
    return;
  }
  if ((cVar1 < '\0') ||
     (('\x1f' < cVar1 || ((*(uint *)(&DAT_008034cc + cVar1 * 0xc) & 0x1000) == 0)))) {
    FUN_005506f0(0,param_1 + 0x30,0x40a00000,0xffffffff);
    uVar3 = FUN_0067a600();
    fVar2 = _DAT_02920d84;
    if (uVar3 < 0x20) {
      if ((*(uint *)(&DAT_008034cc + uVar3 * 0xc) & 0x1000) != 0) goto LAB_004cf80a;
      if (_DAT_02920d84 != 2e+06) {
        iVar4 = FUN_0067a670();
        if (((iVar4 == 1) || (iVar4 == 9)) && (*(float *)(param_1 + 0x34) < fVar2)) {
          iVar4 = 1;
          pcVar5 = "FS_WaterJump";
          goto LAB_004cf74b;
        }
      }
    }
  }
  else {
LAB_004cf80a:
    iVar4 = 2;
    pcVar5 = "imp_thermalDet_attach";
LAB_004cf74b:
    FUN_00681f40(pcVar5,param_1 + 0x30);
    *(uint *)(param_1 + 0x144) = *(uint *)(param_1 + 0x144) | 2;
    if (*(code **)(param_1 + 0x1c8) != (code *)0x0) {
      (**(code **)(param_1 + 0x1c8))(param_1);
    }
    if (iVar4 == 2) goto LAB_004cf792;
  }
  if (_DAT_00951000 <= 0.0) {
    FUN_00571ba0(param_1);
    FUN_00681f40("ThermalDet_Bnce",param_1 + 0x30);
  }
LAB_004cf792:
  if (((*(uint *)(param_1 + 0x144) & 1) != 0) && ((*(uint *)(param_1 + 0x144) & 2) == 0)) {
    fStack_c = *(float *)(param_1 + 0xa4) - *(float *)(param_1 + 0xb0) * *(float *)(param_1 + 0xe0);
    fStack_8 = *(float *)(param_1 + 0xa8) - *(float *)(param_1 + 0xb4) * *(float *)(param_1 + 0xe0);
    fStack_4 = *(float *)(param_1 + 0xac) - *(float *)(param_1 + 0xb8) * *(float *)(param_1 + 0xe0);
    FUN_0062c560(*(undefined4 *)(PTR_DAT_00802c54 + 0x134),1,&fStack_c);
  }
  return;
}

