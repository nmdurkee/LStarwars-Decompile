/* Ghidra pseudocode, not original source.
 * ev_d279921681329594f701fe8f20a56ba9d177d693157112987774dc2af4761a09
 * Entry: 0x55d720; label: FUN_0055d720
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0055d720(int param_1,undefined4 *param_2,undefined2 param_3,undefined4 *param_4,int param_5
                 )

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  *(undefined4 *)(param_1 + 0x5c) = *param_2;
  *(undefined4 *)(param_1 + 0x60) = param_2[1];
  *(undefined4 *)(param_1 + 100) = param_2[2];
  *(undefined4 *)(param_1 + 0x80) = *(undefined4 *)(param_1 + 0x5c);
  *(undefined4 *)(param_1 + 0x84) = *(undefined4 *)(param_1 + 0x60);
  *(undefined2 *)(param_1 + 0x27a) = param_3;
  *(undefined2 *)(param_1 + 0x58) = param_3;
  *(undefined2 *)(param_1 + 0x5a) = param_3;
  *(undefined4 *)(param_1 + 0x88) = *(undefined4 *)(param_1 + 100);
  *(undefined4 *)(param_1 + 0x98) = *(undefined4 *)(param_1 + 0x5c);
  _DAT_0093d620 = *(undefined4 *)(param_1 + 0x80);
  *(undefined4 *)(param_1 + 0x9c) = *(undefined4 *)(param_1 + 0x60);
  *(undefined4 *)(param_1 + 0xa0) = *(undefined4 *)(param_1 + 100);
  DAT_0093d624 = *(undefined4 *)(param_1 + 0x84);
  DAT_0093d628 = *(undefined4 *)(param_1 + 0x88);
  *(undefined4 *)(param_1 + 0x8c) = *(undefined4 *)(param_1 + 0x80);
  uVar1 = *(undefined4 *)(param_1 + 0x5c);
  *(undefined4 *)(param_1 + 0x90) = *(undefined4 *)(param_1 + 0x84);
  uVar2 = *(undefined4 *)(param_1 + 0x60);
  *(undefined4 *)(param_1 + 0x1cc) = uVar1;
  *(undefined4 *)(param_1 + 0x1b4) = uVar1;
  *(undefined4 *)(param_1 + 0x10bc) = uVar1;
  *(undefined4 *)(param_1 + 0x94) = *(undefined4 *)(param_1 + 0x88);
  uVar1 = *(undefined4 *)(param_1 + 100);
  *(undefined4 *)(param_1 + 0x1d0) = uVar2;
  *(undefined4 *)(param_1 + 0x1b8) = uVar2;
  *(undefined4 *)(param_1 + 0x10c0) = uVar2;
  *(undefined4 *)(param_1 + 0x1d4) = uVar1;
  *(undefined4 *)(param_1 + 0x1bc) = uVar1;
  *(undefined4 *)(param_1 + 0x10c4) = uVar1;
  *(undefined4 *)(param_1 + 0xdf8) = DAT_0093b0cc;
  *(undefined4 *)(param_1 + 0xdfc) = DAT_0093b0d0;
  uVar1 = DAT_0093b0d4;
  *(undefined4 *)(param_1 + 0xe00) = DAT_0093b0d4;
  *(undefined4 *)(param_1 + 0x68) = *(undefined4 *)(param_1 + 0xdf8);
  *(undefined4 *)(param_1 + 0x6c) = *(undefined4 *)(param_1 + 0xdfc);
  *(undefined4 *)(param_1 + 0x70) = uVar1;
  FUN_005728a0(param_1);
  if (param_5 != 0) {
    FUN_00572660(param_1,0);
  }
  if (param_4 != (undefined4 *)0x0) {
    *(undefined4 *)(param_1 + 0x420) = *param_4;
    *(undefined4 *)(param_1 + 0x424) = param_4[1];
    *(undefined4 *)(param_1 + 0x428) = param_4[2];
    *(undefined4 *)(param_1 + 0x42c) = param_4[3];
    *(undefined4 *)(param_1 + 0x430) = param_4[4];
    *(undefined4 *)(param_1 + 0x434) = param_4[5];
    return;
  }
  FUN_0052f800(*(undefined4 *)(PTR_DAT_00802c54 + 0x2ae8),param_1,param_1 + 0x2c8,0xff,1);
  return;
}

