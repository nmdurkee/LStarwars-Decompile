/* Ghidra pseudocode, not original source.
 * ev_2606baf984ee455df312fc83a5be5e2bd228e340f9dbc5529ae9524aab57b603
 * Entry: 0x47a2d0; label: FUN_0047a2d0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0047a2d0(undefined4 param_1)

{
  short *psVar1;
  short sVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  undefined4 uVar6;
  int in_ECX;
  float10 extraout_ST0;
  float local_108;
  char local_104 [256];
  uint local_4;
  
  local_4 = DAT_00829570 ^ (uint)&local_108;
  psVar1 = (short *)(DAT_00956290 + in_ECX * 0x1c);
  uVar3 = FUN_006e6b90();
  FUN_0059b840();
  if (DAT_0095628c == 0) {
    sVar2 = *psVar1;
    if (sVar2 != -1) {
      FUN_0050d910(*(undefined4 *)(DAT_00926c20 + sVar2 * 4),0,_DAT_007f92e4,0x3f800000,
                   _DAT_007f92e8,_DAT_007f92e8,_DAT_007f92e8,0,DAT_007f92f4,DAT_007f92f8,
                   DAT_00879b1c,0x3fd9999a,1,0,0,uVar3);
    }
  }
  else {
    if (DAT_0093b314 == 0) {
      iVar4 = FUN_006e6b90(0x3f800000,0x3f800000,0);
      local_108 = (_DAT_00805270 + _DAT_007f92e4) - _DAT_00805278;
      FUN_004b86f0(*(undefined4 *)(PTR_DAT_007fa200 + 4),local_108,100,100,
                   (&DAT_029899a0)[iVar4 >> 1 & 0x7fff]);
      _sprintf(local_104,"%i/%i",DAT_00956268,DAT_00956274);
      FUN_0050c780(local_104,*(undefined4 *)(PTR_DAT_007fa200 + 4),_DAT_007f92e4,0x3f800000,
                   _DAT_00805274,_DAT_00805274,_DAT_00805274,0,0xff,0,0x7f,uVar3);
    }
    else {
      iVar4 = FUN_006e6b90();
      uVar5 = iVar4 >> 1 & 0x7fff;
      local_108 = (_DAT_00805270 + _DAT_007f92e4) - _DAT_00805278;
      FUN_004b86f0(*(undefined4 *)(PTR_DAT_007fa200 + 4),local_108,100,100,(&DAT_029899a0)[uVar5],
                   (float)extraout_ST0,(float)extraout_ST0,0);
      _sprintf(local_104,"%i/%i",DAT_00956278,DAT_00956270);
      FUN_0050c780(local_104,*(undefined4 *)(PTR_DAT_007fa200 + 4),_DAT_007f92e4,0x3f800000,
                   _DAT_00805274,_DAT_00805274,_DAT_00805274,0,0xff,0,0x7f,uVar3);
      uVar6 = FUN_006e6b90();
      local_108 = _DAT_007f9310 + _DAT_007f92e4;
      FUN_0050d910(*(undefined4 *)(DAT_00926c20 + DAT_00880884 * 4),
                   *(undefined4 *)(PTR_DAT_007fa200 + 4),local_108,0x3f800000,_DAT_007f9314,
                   _DAT_007f9314,_DAT_007f9314,0,DAT_007f931c,DAT_007f9320,DAT_007f9324,
                   _DAT_007f9318,1,0,0,uVar6);
      local_108 = (_DAT_00805270 + _DAT_007f92e4) - _DAT_00805278;
      FUN_004b86f0(*(undefined4 *)(PTR_DAT_007fa200 + 0x10),local_108,100,100,(&DAT_029899a0)[uVar5]
                   ,0x3f800000,0x3f800000,0);
      _sprintf(local_104,"%i/%i",DAT_00956280,DAT_00956260);
      FUN_0050c780(local_104,*(undefined4 *)(PTR_DAT_007fa200 + 0x10),_DAT_007f92e4,0x3f800000,
                   _DAT_00805274,_DAT_00805274,_DAT_00805274,0,0xff,0,0x7f,uVar3);
      uVar6 = FUN_006e6b90();
      local_108 = _DAT_007f9310 + _DAT_007f92e4;
      FUN_0050d910(*(undefined4 *)(DAT_00926c20 + DAT_00880888 * 4),
                   *(undefined4 *)(PTR_DAT_007fa200 + 0x10),local_108,0x3f800000,_DAT_007f9314,
                   _DAT_007f9314,_DAT_007f9314,0,DAT_007f931c,DAT_007f9320,DAT_007f9324,
                   _DAT_007f9318,1,0,0,uVar6);
    }
    FUN_00478b00(*(undefined4 *)PTR_DAT_007fa200,_DAT_007f92e4,DAT_00956250,param_1);
    FUN_00478d20(0xd2,*(undefined4 *)(PTR_DAT_007fa200 + 8),_DAT_007f92e4,param_1,DAT_0095626c,
                 DAT_0095627c);
    FUN_00478d20(0xd3,*(undefined4 *)(PTR_DAT_007fa200 + 0xc),_DAT_007f92e4,param_1,DAT_00956258,
                 DAT_0095625c);
    DAT_00879b70 = 1;
    FUN_00478b00(*(undefined4 *)(PTR_DAT_007fa200 + 0x14),_DAT_007f92e4,DAT_00956288,param_1);
  }
  sVar2 = psVar1[1];
  if (sVar2 == -1) {
    __security_check_cookie(local_4 ^ (uint)&local_108);
    return;
  }
  FUN_0050d910(*(undefined4 *)(DAT_00926c20 + sVar2 * 4),0,_DAT_007f92ec,0x3f800000,_DAT_007f92f0,
               _DAT_007f92f0,_DAT_007f92f0,0,DAT_007f92f4,DAT_007f92f8,DAT_00879b1c,0x3fd9999a,1,0,0
               ,uVar3);
  __security_check_cookie(local_4 ^ (uint)&local_108);
  return;
}

