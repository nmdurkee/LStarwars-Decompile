/* Ghidra pseudocode, not original source.
 * ev_1ed2ee538169644958bcf6b45e609dd0f8f5843391a9d69ffaf951ca25289b49
 * Entry: 0x64f5d0; label: FUN_0064f5d0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0064f5d0(int param_1)

{
  int iVar1;
  int extraout_ECX;
  int iVar2;
  int iVar3;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  
  iVar2 = 0;
  iVar3 = DAT_0291f664;
  if (0 < DAT_0081020c) {
    do {
      if ((((*(byte *)(iVar3 + 0x144) & 1) != 0) && ((*(uint *)(iVar3 + 0x108) & 0x1000) == 0)) &&
         ((*(code **)(iVar3 + 0x1d0) == (code *)0x0 ||
          (iVar1 = (**(code **)(iVar3 + 0x1d0))(iVar3), iVar1 != 0)))) {
        if ((*(uint *)(iVar3 + 0x144) & 8) == 0) {
          if ((*(uint *)(iVar3 + 0x144) & 0x2000) != 0) {
            _DAT_009716e8 = *(undefined4 *)(iVar3 + 0x1a0);
            _DAT_009716ec = *(undefined4 *)(iVar3 + 0x1a4);
            _DAT_009716f0 = *(undefined4 *)(iVar3 + 0x1a8);
            FUN_005fca90(iVar3 + 0x1a0);
          }
        }
        else {
          FUN_006423b0(iVar3 + 0x17c,iVar3 + 0x164);
          _DAT_009716e8 = *(undefined4 *)(iVar3 + 0x1a0);
          _DAT_009716ec = *(undefined4 *)(iVar3 + 0x1a4);
          _DAT_009716f0 = *(undefined4 *)(iVar3 + 0x1a8);
          FUN_005fca90(iVar3 + 0x1a0);
        }
        *(uint *)(iVar3 + 0x144) = *(uint *)(iVar3 + 0x144) & 0xfffffdff;
        iVar1 = iVar3;
        if (*(float *)(iVar3 + 0x214) != 1.0) {
          FUN_006424c0();
          uStack_4c = *(undefined4 *)(iVar3 + 0x214);
          uStack_48 = uStack_4c;
          uStack_44 = uStack_4c;
          FUN_005b4c30(extraout_ECX,&uStack_4c);
          iVar1 = extraout_ECX;
        }
        if ((*(int *)(iVar3 + 0x154) == 0) ||
           (iVar1 = FUN_005f33b0(iVar3 + 0x148,iVar1), iVar1 == 0)) {
          if ((param_1 == 0) &&
             (((*(byte *)(iVar3 + 0x108) & 0x10) == 0 || ((*(uint *)(iVar3 + 0x144) & 0x100) != 0)))
             ) {
            FUN_0064ac90(iVar3,0);
          }
        }
        else {
          *(uint *)(iVar3 + 0x144) = *(uint *)(iVar3 + 0x144) | 0x600;
        }
      }
      iVar2 = iVar2 + 1;
      iVar3 = iVar3 + 0x220;
    } while (iVar2 < DAT_0081020c);
  }
  return;
}

