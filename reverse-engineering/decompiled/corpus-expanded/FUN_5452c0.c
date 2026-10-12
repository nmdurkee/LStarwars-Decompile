/* Ghidra pseudocode, not original source.
 * ev_c5dfc397922749c3a3d752de14fd9803558ba6adea5c02b0f86cafc5797b3dfb
 * Entry: 0x5452c0; label: FUN_005452c0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

void FUN_005452c0(undefined4 param_1)

{
  float *pfVar1;
  int iVar2;
  float *pfVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int local_309c;
  int local_3098;
  int local_3094;
  undefined4 local_3090;
  float local_308c;
  undefined4 local_3088;
  undefined4 local_3084;
  undefined4 local_3080;
  undefined4 local_307c;
  float local_3078;
  undefined4 local_3074;
  undefined4 local_3070;
  undefined4 local_306c;
  float local_3068;
  undefined4 local_3064;
  int local_3060 [8];
  undefined1 local_3040 [48];
  undefined4 local_3010;
  float local_300c;
  undefined4 local_3008;
  float local_3000 [1536];
  float local_1800 [1535];
  undefined4 uStack_4;
  
  uStack_4 = 0x5452ca;
  iVar4 = 0;
  if (DAT_029892c0 != 0) {
    iVar2 = 0;
    local_3098 = 0;
    local_3060[0] = 0;
    pfVar3 = (float *)&DAT_02984564;
    local_3094 = 8;
    do {
      if ((*(char *)(pfVar3 + -0x2c1) != '\0') && (*(char *)(pfVar3 + -8) != '\0')) {
        *(undefined1 *)((int)pfVar3 + -0x1f) = 0;
        FUN_005b4670(local_3040,(int)*(short *)((int)pfVar3 + -0x16));
        local_3080 = 0;
        local_309c = 0;
        local_307c = 0;
        local_3078 = -*pfVar3;
        local_3074 = 0x3f800000;
        local_3070 = 0;
        local_306c = 0;
        local_3068 = *pfVar3;
        local_3064 = 0x3f800000;
        if ('\0' < *(char *)((int)pfVar3 + -0x1e)) {
          pfVar1 = pfVar3 + -0x19e;
          iVar5 = iVar2 * 0xc;
          do {
            iVar4 = FUN_005cfac0(pfVar3 + -0x1e);
            if ((iVar4 != 0) && (iVar4 = FUN_005f33b0(pfVar3 + -0x1e,pfVar1), iVar4 != 0)) {
              *(undefined1 *)((int)pfVar3 + -0x1f) = 1;
            }
            iVar6 = iVar5;
            if ((local_309c % (int)*(char *)((int)pfVar3 + -0x1d) == 0) &&
               (iVar4 = FUN_005cfac0(pfVar3 + -0x1b), iVar4 != 0)) {
              FUN_005c03e0(&local_3090,&local_3080,pfVar1);
              if (iVar2 < 0x200) {
                *(undefined4 *)((int)local_1800 + iVar5) = local_3090;
                *(float *)((int)local_1800 + iVar5 + 4) = pfVar3[1] + local_308c;
                *(undefined4 *)((int)local_1800 + iVar5 + 8) = local_3088;
              }
              local_3010 = local_3090;
              local_300c = local_308c;
              local_3008 = local_3088;
              FUN_005f33b0(pfVar3 + -0x1b,local_3040);
              local_3090 = 0;
              local_308c = 0.0;
              local_3088 = 0x3f800000;
              local_3084 = 0x3f800000;
              FUN_005c03e0(&local_3090,&local_3070,pfVar1);
              if (iVar2 < 0x200) {
                *(undefined4 *)((int)local_3000 + iVar5) = local_3090;
                iVar2 = iVar2 + 1;
                iVar6 = iVar5 + 0xc;
                *(float *)((int)local_3000 + iVar5 + 4) = pfVar3[1] + local_308c;
                *(undefined4 *)((int)local_3000 + iVar5 + 8) = local_3088;
              }
              local_3010 = local_3090;
              local_300c = local_308c;
              local_3008 = local_3088;
              FUN_005f33b0(pfVar3 + -0x1b,local_3040);
            }
            local_309c = local_309c + 1;
            pfVar1 = pfVar1 + 0x10;
            iVar4 = local_3098;
            iVar5 = iVar6;
          } while (local_309c < *(char *)((int)pfVar3 + -0x1e));
        }
        if (local_3060[iVar4] != iVar2) {
          iVar4 = iVar4 + 1;
          local_3060[iVar4] = iVar2;
          local_3098 = iVar4;
        }
      }
      pfVar3 = pfVar3 + 0x2c3;
      local_3094 = local_3094 + -1;
    } while (local_3094 != 0);
    local_3060[iVar4 + 1] = iVar2;
    if (1 < iVar2) {
      FUN_00545240(param_1,local_1800,local_3000,iVar2,local_3060,DAT_02984548);
    }
  }
  return;
}

