/* Ghidra analysis pseudocode, not original source.
 * ev_6fbd3af984a39447bc9fe9dd191dc75e4e15fa1d77defc2a7b40b22f43e8d294
 * Entry: 0x67a3b0; label: FUN_0067a3b0
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0067a3b0(void)

{
  float fVar1;
  byte bVar2;
  short sVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  float10 fVar8;
  float local_c;
  float local_8;
  float local_4;
  
  iVar5 = DAT_0292186c;
  bVar2 = *(byte *)(DAT_0292186c + 0x88);
  if (((bVar2 != 0) && (sVar3 = *(short *)(DAT_0292186c + 0x6c), sVar3 != -1)) &&
     (*(int *)(*DAT_0292fc68 + 0x2c + sVar3 * 0x38) == 1)) {
    local_c = *(float *)(DAT_0292186c + 0xa8);
    local_4 = *(float *)(DAT_0292186c + 0xb0);
    local_8 = *(float *)(DAT_0292186c + 0xac);
    DAT_02961fdc = sVar3;
    switch(bVar2) {
    case 2:
    case 3:
    case 4:
    case 0x12:
    case 0x13:
    case 0x14:
      FUN_0066f9a0(&local_c,&local_c);
      if ((bVar2 & 0x10) == 0) {
        local_c = local_c * *(float *)(iVar5 + 0x58);
        local_8 = local_8 * *(float *)(iVar5 + 0x58);
        local_4 = local_4 * *(float *)(iVar5 + 0x58);
      }
    case 1:
    case 0x11:
      if (*(float *)(iVar5 + 0x5c) != 1.0) {
        fVar8 = (float10)FUN_005c0240(*(float *)(iVar5 + 0x68) * local_8 * local_8 +
                                      local_c * local_c + local_4 * local_4);
        fVar8 = (float10)FUN_0064fde0(0x3f800000,(float)fVar8);
        fVar1 = (float)fVar8;
        local_c = fVar1 * local_c;
        local_8 = *(float *)(DAT_0292186c + 100) * fVar1 * local_8;
        local_4 = fVar1 * local_4;
        iVar5 = DAT_0292186c;
      }
      _DAT_02961f74 = (int)*(short *)(*DAT_0292fc68 + 0x30 + *(short *)(iVar5 + 0x6c) * 0x38);
      _DAT_02961fa4 = local_8;
      puVar6 = *(undefined4 **)(iVar5 + 0x90);
      puVar7 = &DAT_0292fc78;
      for (iVar4 = 0x19; iVar4 != 0; iVar4 = iVar4 + -1) {
        *puVar7 = *puVar6;
        puVar6 = puVar6 + 1;
        puVar7 = puVar7 + 1;
      }
      _DAT_02961fa0 = local_c;
      _DAT_02961fa8 = local_4;
    }
  }
  return;
}

