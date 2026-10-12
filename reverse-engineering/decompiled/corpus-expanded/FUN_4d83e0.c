/* Ghidra pseudocode, not original source.
 * ev_39fbc79f0f4753fe71d498de82ca90498367aadd8f8860e7e5955d3b79e5f355
 * Entry: 0x4d83e0; label: FUN_004d83e0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004d83e0(void)

{
  short sVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  char *pcVar6;
  
  if (((DAT_00951b50 == 0) && (_DAT_008828ec = _DAT_008828ec + _DAT_00925018, DAT_008827ea != 0)) &&
     (_DAT_007ffcc8 < _DAT_008828ec)) {
    iVar2 = FUN_005b9e90(0);
    iVar2 = iVar2 % (int)DAT_008827ea;
    if (DAT_00876ce8 < 4) {
      uVar3 = (int)DAT_008828f0 + 1U & 0x80000003;
      if ((int)uVar3 < 0) {
        uVar3 = (uVar3 - 1 | 0xfffffffc) + 1;
      }
      DAT_008828f0 = (short)uVar3;
      iVar4 = (&DAT_008827ec)[iVar2];
      uVar5 = *(undefined4 *)(iVar4 + 0x1c);
      pcVar6 = "Wildlife";
      sVar1 = *(short *)(&DAT_008828f4 + DAT_008828f0 * 2);
    }
    else {
      uVar3 = FUN_005b9e90(0);
      iVar4 = (&DAT_008827ec)[iVar2];
      uVar5 = *(undefined4 *)(iVar4 + 0x1c);
      if ((uVar3 & 1) == 0) {
        pcVar6 = "Battledroid";
        sVar1 = DAT_007f1888;
      }
      else {
        pcVar6 = "STAP";
        sVar1 = DAT_007f19b8;
      }
    }
    iVar4 = FUN_0043d890((int)sVar1,iVar4 + 0x10,uVar5,pcVar6,iVar4 + 0x20,0,0,0,0,0,0);
    if (iVar4 != 0) {
      *(undefined4 *)(iVar4 + 0x36c) = (&DAT_0088286c)[iVar2];
    }
    _DAT_008828ec = 0.0;
  }
  return;
}

