/* Ghidra pseudocode, not original source.
 * ev_82279d4937da693375712195ef93cdd3155885c4c37192da562bbaf9be35e879
 * Entry: 0x4e73d0; label: FUN_004e73d0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004e73d0(void)

{
  short sVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40 [12];
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  FUN_004e6b70();
  if (DAT_00951b50 == 0) {
    sVar1 = FUN_006e6b90((int)DAT_0088a276);
    DAT_0088a27c = DAT_0088a27c + sVar1;
    sVar1 = FUN_006e6b90((int)DAT_0088a278);
    DAT_0088a27e = DAT_0088a27e + sVar1;
    sVar1 = FUN_006e6b90((int)DAT_0088a27a);
    DAT_0088a280 = DAT_0088a280 + sVar1;
    if (DAT_00951b54 != 0) {
      *DAT_0088a240 = DAT_0088a27c;
      DAT_0088a240[1] = DAT_0088a27e;
      DAT_0088a240[2] = DAT_0088a280;
    }
  }
  else {
    DAT_0088a27c = FUN_00550070(DAT_0088a27c,*DAT_0088a240,0x40e00000);
    DAT_0088a27e = FUN_00550070(DAT_0088a27e,DAT_0088a240[1],0x40e00000);
    DAT_0088a280 = FUN_00550070(DAT_0088a280,DAT_0088a240[2],0x40e00000);
  }
  _DAT_0088a544 = (undefined4 *)FUN_005cfa20(&DAT_0088a248);
  if (_DAT_0088a544 != (undefined4 *)0x0) {
    puVar3 = _DAT_0088a544;
    puVar4 = local_40;
    for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar4 = *puVar3;
      puVar3 = puVar3 + 1;
      puVar4 = puVar4 + 1;
    }
    FUN_005b6ec0(local_40,&local_4c);
    FUN_005b4f70(local_40,(int)DAT_0088a27e);
    FUN_005b4dd0(local_40,(int)DAT_0088a27c);
    FUN_005b5060(local_40,(int)DAT_0088a280);
    local_10 = local_4c;
    local_c = local_48;
    local_8 = local_44;
    FUN_005ea570(&DAT_0088a248,local_40);
    FUN_005ea660(&DAT_0088a248);
  }
  iVar2 = 0;
  if (0 < DAT_0088a274) {
    do {
      if ((&DAT_0088a254)[iVar2] != 0) {
        *(short *)((&DAT_0088a254)[iVar2] + 0xe8) = DAT_0088a27c;
        *(short *)((&DAT_0088a254)[iVar2] + 0xea) = DAT_0088a27e;
        *(short *)((&DAT_0088a254)[iVar2] + 0xec) = DAT_0088a280;
        *(uint *)((&DAT_0088a254)[iVar2] + 0x94) =
             *(uint *)((&DAT_0088a254)[iVar2] + 0x94) | 0x10000;
        FUN_005687f0((&DAT_0088a254)[iVar2]);
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < DAT_0088a274);
  }
  return;
}

