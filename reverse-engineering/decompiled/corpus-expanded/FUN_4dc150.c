/* Ghidra pseudocode, not original source.
 * ev_8ce8f2cf434fcaf80bd354ce8b1c39ad0b90beb929885cf3a95e877f90223845
 * Entry: 0x4dc150; label: FUN_004dc150
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_004dc150(void)

{
  float fVar1;
  int iVar2;
  int iVar3;
  
  fVar1 = _DAT_0088249c;
  if (_DAT_0088249c <= 0.0) {
    return 0;
  }
  if (_DAT_00950780 == 0.0) {
    _DAT_0088249c = _DAT_0088249c - _DAT_00925018;
  }
  if (DAT_0093d7f0 != 0) {
    if (_DAT_0088249c <= 0.0) {
      *(undefined4 *)(DAT_0093d7f0 + 0xed4) = 0x4e6e6b28;
    }
    else {
      *(undefined4 *)(DAT_0093d7f0 + 0xdc8) = 0;
      *(undefined4 *)(DAT_0093d7f0 + 0x70) = 0;
      *(undefined4 *)(DAT_0093d7f0 + 0x68) = 0;
      *(undefined4 *)(DAT_0093d7f0 + 0xed4) = 0;
    }
  }
  if (DAT_0093d7f4 != 0) {
    if (_DAT_0088249c <= 0.0) {
      *(undefined4 *)(DAT_0093d7f4 + 0xed4) = 0x4e6e6b28;
    }
    else {
      *(undefined4 *)(DAT_0093d7f4 + 0xdc8) = 0;
      *(undefined4 *)(DAT_0093d7f4 + 0x70) = 0;
      *(undefined4 *)(DAT_0093d7f4 + 0x68) = 0;
      *(undefined4 *)(DAT_0093d7f4 + 0xed4) = 0;
    }
  }
  if ((_DAT_0088249c < 2.9) && (2.9 < fVar1 != (fVar1 == 2.9))) {
    FUN_00681f40("PodX_EngStartup1",0);
  }
  if ((_DAT_0088249c < 1.5) && (1.5 < fVar1 != (fVar1 == 1.5))) {
    FUN_00681f40("PodX_EngStartup2",0);
  }
  if (_DAT_0088249c < 0.0 == (_DAT_0088249c == 0.0)) {
    iVar2 = FUN_006e6b90();
    iVar3 = FUN_006e6b90();
    if (iVar2 != iVar3) {
      FUN_00681f40("Pod_Race_Light",0);
    }
    return 1;
  }
  FUN_00681f40("Pod_Race_Go",0);
  return 1;
}

