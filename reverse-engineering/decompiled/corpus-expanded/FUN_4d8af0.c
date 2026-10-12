/* Ghidra pseudocode, not original source.
 * ev_39fbc79f0f4753fe71d498de82ca90498367aadd8f8860e7e5955d3b79e5f355
 * Entry: 0x4d8af0; label: FUN_004d8af0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int * FUN_004d8af0(void)

{
  float fVar1;
  undefined2 uVar2;
  int *in_EAX;
  int iVar3;
  uint uVar4;
  int iVar5;
  int *piVar6;
  bool bVar7;
  float10 fVar8;
  float local_2c;
  int local_24;
  float local_20;
  int local_1c;
  undefined4 local_18;
  float local_14;
  undefined4 local_10;
  undefined1 local_c [12];
  
  fVar8 = (float10)FUN_005506f0(0);
  local_2c = (float)fVar8;
  if (local_2c == 2e+06) {
    local_2c = (float)in_EAX[1];
  }
  local_24 = *in_EAX;
  local_20 = _DAT_008823d4 * _DAT_007ffd00 + local_2c;
  local_1c = in_EAX[2];
  iVar5 = 0;
  if (0 < DAT_00882404) {
    do {
      iVar3 = FUN_0043bb20((&DAT_008823dc)[iVar5],&local_24,_DAT_007ffcfc * _DAT_008823d4);
      if (iVar3 != 0) {
        return (int *)0x0;
      }
      iVar5 = iVar5 + 1;
    } while (iVar5 < DAT_00882404);
  }
  fVar8 = (float10)FUN_005bed80(&local_24,DAT_0093d810 + 0x80,local_c);
  fVar1 = (float)fVar8;
  if (0.0 < fVar1) {
    FUN_005b3830(local_c,local_c,1.0 / fVar1);
    local_18 = *(undefined4 *)(DAT_0093d810 + 0x80);
    local_14 = *(float *)(DAT_0093d810 + 0x84) + 100.0;
    local_10 = *(undefined4 *)(DAT_0093d810 + 0x88);
    iVar5 = FUN_0062a9a0(&local_18,local_c,0,0,_DAT_007ffcfc * _DAT_008823d4 + fVar1,0x40a00000);
    if (iVar5 != 0) {
      return (int *)0x0;
    }
  }
  piVar6 = &DAT_00881cd4;
  iVar5 = 0;
  do {
    if (*piVar6 == 0) {
      bVar7 = DAT_007ffd04 != 0;
      piVar6[5] = 0;
      piVar6[1] = local_24;
      piVar6[2] = (int)local_20;
      *piVar6 = 1;
      piVar6[3] = local_1c;
      if (bVar7) {
        uVar4 = FUN_005b9e30();
        *(short *)(piVar6 + 6) = (short)(uVar4 % DAT_007ffd04);
      }
      uVar2 = FUN_005b9e30();
      *(undefined2 *)((int)piVar6 + 0x1a) = uVar2;
      uVar4 = 1 << ((byte)iVar5 & 0x1f);
      _DAT_00882a48 = _DAT_00882a48 | uVar4;
      _DAT_00882a4c = _DAT_00882a4c | (int)uVar4 >> 0x1f;
      _DAT_008827c8 = _DAT_008827c8 & ~uVar4;
      _DAT_008827cc = _DAT_008827cc & (int)~uVar4 >> 0x1f;
      _DAT_008827e4 = _DAT_008827e4 + 1;
      return piVar6;
    }
    iVar5 = iVar5 + 1;
    piVar6 = piVar6 + 7;
  } while (iVar5 < 0x40);
  return (int *)0x0;
}

