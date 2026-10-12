/* Ghidra pseudocode, not original source.
 * ev_6ff60c7644817ef8ef03e73cfdcec4dc91928e5367edba007261837c31d60754
 * Entry: 0x4b4ac0; label: FUN_004b4ac0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004b4ac0(float param_1)

{
  float fVar1;
  short sVar2;
  int iVar3;
  float fVar4;
  int iVar5;
  uint uVar6;
  undefined4 uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  
  iVar5 = (int)param_1;
  uVar12 = *(uint *)(*(int *)((int)param_1 + 0xca4) + 8);
  uVar8 = *(uint *)(*(int *)((int)param_1 + 0xca4) + 4);
  uVar10 = uVar8 & DAT_0080227c;
  uVar11 = uVar12 & DAT_0080227c;
  uVar8 = uVar8 & DAT_00802278;
  uVar6 = uVar12 & DAT_00802284;
  uVar9 = uVar12 & DAT_00802280;
  sVar2 = *(short *)((int)param_1 + 0x1064);
  uVar12 = uVar12 & DAT_00802278;
  if ((((sVar2 == DAT_007f1884) || (sVar2 == DAT_007f1924)) || (sVar2 == DAT_007f1928)) ||
     (sVar2 == DAT_007f1874)) {
    FUN_0058d8b0(param_1);
  }
  FUN_00427b40(param_1);
  if (((DAT_00951154 != 0) && (DAT_00951288 != 0)) &&
     (((*(uint *)(*(int *)((int)param_1 + 0x54) + 4) & 0x4000000) != 0 &&
      (*(undefined1 **)((int)param_1 + 0xcc4) != (undefined1 *)0x0)))) {
    **(undefined1 **)((int)param_1 + 0xcc4) = 0;
  }
  if ((*(byte *)((int)param_1 + 0xe20) & 0x20) != 0) {
    return;
  }
  if ((*(byte *)((int)param_1 + 0x1fc) & 0x80) != 0) {
    iVar3 = *(int *)(*(int *)((int)param_1 + 0x54) + 0x24);
    if (((*(char *)(iVar3 + 0x116) == '\x02') && (*(char *)((int)param_1 + 0x7b5) != '+')) &&
       (*(char *)((int)param_1 + 0xe32) == '\x01')) {
      fVar4 = (*(float *)((int)param_1 + 0x22c) / *(float *)(iVar3 + 0x1c)) * _DAT_00925018 +
              *(float *)((int)param_1 + 0xd64);
      *(float *)((int)param_1 + 0xd64) = fVar4;
      if (*(char *)((int)param_1 + 0x281) == '\0') {
        fVar1 = *(float *)(*(int *)(*(int *)((int)param_1 + 0x54) + 0x24) + 0x48);
        if ((fVar1 < fVar4 == (fVar1 == fVar4)) && (*(char *)((int)param_1 + 0x285) != '\x1a')) {
          *(undefined4 *)((int)param_1 + 0x6c) = 0;
          goto LAB_004b4c69;
        }
        FUN_0049dc60(param_1,0);
      }
      else {
        *(undefined1 *)((int)param_1 + 0xe32) = 0;
        *(undefined1 *)((int)param_1 + 0x7b5) = 0xff;
      }
    }
  }
  iVar3 = *(int *)(*(int *)((int)param_1 + 0x54) + 0x24);
  if ((*(char *)(iVar3 + 0x116) == '\x02') && (*(char *)((int)param_1 + 0xe32) == '\x01')) {
    uVar7 = *(undefined4 *)(iVar3 + 0x28);
  }
  else {
    uVar7 = 0;
  }
  FUN_004abac0(param_1,0,uVar7,0x41000000,0);
LAB_004b4c69:
  if ((*(short *)((int)param_1 + 0x1064) == DAT_007f1ac4) &&
     (*(char *)((int)param_1 + 0x7b5) == '5')) {
    param_1 = _DAT_007fc144;
    if (*(float *)(iVar5 + 0x21c) != 2e+06) {
      param_1 = *(float *)(iVar5 + 0x1a0) - *(float *)(iVar5 + 0x21c);
      if (_DAT_007fc14c < param_1) {
        param_1 = _DAT_007fc14c;
      }
      param_1 = _DAT_007fc144 * (param_1 / _DAT_007fc14c) +
                (1.0 - param_1 / _DAT_007fc14c) * _DAT_007fc148;
    }
    if (*(float *)(iVar5 + 0x6c) < param_1) {
      *(float *)(iVar5 + 0x6c) = param_1;
    }
  }
  FUN_004cdab0(PTR_DAT_00802c54,iVar5);
  if (*(int *)(iVar5 + 0xcbc) != 0) {
    FUN_004c85e0(PTR_DAT_00802c54,iVar5);
  }
  FUN_0049c080(iVar5);
  FUN_004a7880(iVar5);
  FUN_004a7610(iVar5);
  FUN_0049be00(iVar5);
  FUN_0056c7a0(iVar5);
  FUN_004827a0(PTR_DAT_00802c54,iVar5);
  if (DAT_00950c48 != 0) {
    FUN_0056b8f0(iVar5);
  }
  FUN_0056c0e0(iVar5);
  FUN_004d18a0(iVar5,uVar12);
  FUN_004a3be0();
  FUN_004a4a20(iVar5);
  FUN_0056d8c0(iVar5,PTR_DAT_00802c54);
  FUN_004b0c80();
  if ((DAT_007f39e4 == 0) || (DAT_00876580 != 0)) {
    uVar7 = 0;
  }
  else {
    uVar7 = 1;
  }
  FUN_0059bd40(iVar5,uVar7);
  FUN_005623f0(iVar5);
  if (*(short *)(iVar5 + 0x1064) != DAT_007f1aa8) {
    FUN_00488770(iVar5,uVar6);
  }
  FUN_0049d720(iVar5);
  iVar3 = *(int *)(*(int *)(iVar5 + 0x54) + 0x24);
  if ((*(char *)(iVar3 + 0x116) == '\x02') && (*(char *)(iVar5 + 0xe32) == '\x01')) {
    FUN_0049dd10(iVar5,uVar12,0,0);
  }
  else if ((*(byte *)(iVar3 + 0x94) & 4) == 0) {
    uVar6 = (-(uint)(*(short *)(iVar5 + 0x1064) != DAT_007f1884) & 0xffffffe8) + 0x20;
    if ((*(uint *)(iVar3 + 0x90) & 0x400000) != 0) {
      uVar6 = uVar6 | 0x101;
    }
    FUN_00562570(iVar5,uVar12,uVar8,uVar6,uVar11,uVar10,0xffffffff);
  }
  FUN_0046eda0(PTR_DAT_00802c54,iVar5,uVar9);
  FUN_00474070(PTR_DAT_00802c54,iVar5,uVar9);
  FUN_004d6060(iVar5,uVar9);
  if ((*(uint *)(*(int *)(iVar5 + 0x54) + 4) & 0x100000) != 0) {
    FUN_0054ea40(iVar5);
  }
  FUN_00592280(iVar5);
  FUN_00490d10(PTR_DAT_00802c54,iVar5);
  FUN_004d0290(iVar5);
  if ((*(uint *)(*(int *)(iVar5 + 0x54) + 4) & 0x40000) != 0) {
    FUN_004ce830(iVar5,uVar9);
  }
  if ((DAT_007f39e4 == 0) && (DAT_00876580 == 0)) {
    if ((*(int *)(iVar5 + 0xcbc) != 0) && ((*(byte *)(*(int *)(iVar5 + 0xcbc) + 0xc) & 4) != 0)) {
      FUN_004271b0(iVar5);
    }
    if ((*(int *)(iVar5 + 0xcbc) != 0) && ((*(byte *)(*(int *)(iVar5 + 0xcbc) + 0xc) & 8) != 0)) {
      FUN_004c88c0(PTR_DAT_00802c54,iVar5);
    }
    if ((*(byte *)(*(int *)(iVar5 + 0x54) + 4) & 8) == 0) {
      FUN_004d4dc0(PTR_DAT_00802c54,iVar5);
    }
  }
  FUN_00598880(PTR_DAT_00802c54,iVar5);
  FUN_0056a5b0(PTR_DAT_00802c54,iVar5);
  if (*(short *)(iVar5 + 0x1064) == DAT_007f1ac8) {
    if ((*(byte *)(iVar5 + 0xeec) & 0x10) == 0) {
      if (*(float *)(iVar5 + 0xd3c) == 1.0) {
        FUN_0058da10(iVar5);
      }
    }
    else if ((*(float *)(iVar5 + 0xd3c) == 0.0) && (*(char *)(iVar5 + 0x7b5) != '&')) {
      FUN_0058d560(iVar5);
    }
  }
  FUN_0058d6a0(iVar5);
  FUN_0058db50(iVar5);
  FUN_0058dec0(iVar5);
  FUN_0058b210(iVar5);
  FUN_0058e420(iVar5);
  FUN_0049e450(uVar11,uVar10,0,~(*(uint *)(*(int *)(iVar5 + 0x54) + 4) >> 7) & 1);
  FUN_0049ea70(iVar5,uVar11,uVar10,*(uint *)(*(int *)(iVar5 + 0x54) + 4) & 0x80,0,0);
  if ((((*(uint *)(*(int *)(*(int *)(iVar5 + 0x54) + 0x24) + 0x94) & 0x20000000) != 0) &&
      (*(short *)(iVar5 + 0x1064) == DAT_007f17d0)) && (DAT_00876580 != 0)) {
    FUN_005b26b0(iVar5);
  }
  FUN_004b13e0(uVar12);
  FUN_004036a0(PTR_DAT_00802c54,iVar5);
  FUN_004bdaf0(PTR_DAT_00802c54,iVar5);
  if ((*(byte *)(*(int *)(iVar5 + 0x54) + 4) & 0x80) == 0) {
    if (*(int *)(iVar5 + 0xcc0) != 0) {
      FUN_004050c0(iVar5);
    }
  }
  else {
    FUN_004b3d40(iVar5,uVar11,uVar9,1,1,0);
  }
  if ((*(byte *)(*(int *)(*(int *)(iVar5 + 0x54) + 0x24) + 0x94) & 0x80) != 0) {
    FUN_004b29f0(*(uint *)(*(int *)(iVar5 + 0xca4) + 8) & DAT_00802280,0);
  }
  FUN_004a69e0();
  FUN_004a7d00();
  FUN_0049c940();
  FUN_0049c610();
  if (*(short *)(iVar5 + 0x1064) == DAT_007f19ec) {
    FUN_004a82a0(iVar5,0);
  }
  FUN_0058cef0(iVar5);
  FUN_0058cf50(iVar5);
  FUN_0058d150(iVar5);
  return;
}

