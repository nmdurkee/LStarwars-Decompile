/* Ghidra analysis pseudocode, not original source.
 * ev_fc46cff07f0ed537c3533760820ac45bd355561daa184f1b787f47d220e25ab8
 * Entry: 0x41f6d0; label: FUN_0041f6d0
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_0041f6d0(int param_1,undefined4 *param_2,undefined2 param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  
  iVar3 = FUN_0058a900(0);
  if (iVar3 != 0) {
    return 0;
  }
  if (param_1 != 0) {
    iVar3 = FUN_00440120(*(undefined4 *)(PTR_DAT_00802c54 + 0x2ae8),param_1);
    if (((iVar3 != 0) && ((*(uint *)(iVar3 + 0x1fc) & 0x1000) == 0)) &&
       ((DAT_0093b2a4 == 0 || ((*(uint *)(iVar3 + 0x1f8) & 0x400) != 0)))) {
      if (*(char *)(iVar3 + 0x400) == -1) {
        *(uint *)(iVar3 + 0x1fc) = *(uint *)(iVar3 + 0x1fc) | 0x1000;
        FUN_0052c790(iVar3 + 0x2c8,&DAT_00753270);
        if (param_2 != (undefined4 *)0x0) {
          *(undefined4 *)(iVar3 + 0x5c) = *param_2;
          *(undefined4 *)(iVar3 + 0x60) = param_2[1];
          *(undefined4 *)(iVar3 + 100) = param_2[2];
          *(undefined2 *)(iVar3 + 0x27a) = param_3;
          *(undefined2 *)(iVar3 + 0x58) = param_3;
          *(undefined2 *)(iVar3 + 0x5a) = param_3;
          FUN_0052f800(*(undefined4 *)(PTR_DAT_00802c54 + 0x2ae8),iVar3,iVar3 + 0x2c8,0xff,1);
          *(undefined4 *)(iVar3 + 0x80) = *(undefined4 *)(iVar3 + 0x5c);
          *(undefined4 *)(iVar3 + 0x84) = *(undefined4 *)(iVar3 + 0x60);
          *(undefined4 *)(iVar3 + 0x88) = *(undefined4 *)(iVar3 + 100);
          *(undefined4 *)(iVar3 + 0x98) = *(undefined4 *)(iVar3 + 0x5c);
          _DAT_0093d620 = *(undefined4 *)(iVar3 + 0x80);
          *(undefined4 *)(iVar3 + 0x9c) = *(undefined4 *)(iVar3 + 0x60);
          *(undefined4 *)(iVar3 + 0xa0) = *(undefined4 *)(iVar3 + 100);
          DAT_0093d624 = *(undefined4 *)(iVar3 + 0x84);
          DAT_0093d628 = *(undefined4 *)(iVar3 + 0x88);
          *(undefined4 *)(iVar3 + 0x8c) = *(undefined4 *)(iVar3 + 0x80);
          uVar1 = *(undefined4 *)(iVar3 + 0x5c);
          *(undefined4 *)(iVar3 + 0x90) = *(undefined4 *)(iVar3 + 0x84);
          uVar2 = *(undefined4 *)(iVar3 + 0x60);
          *(undefined4 *)(iVar3 + 0x1cc) = uVar1;
          *(undefined4 *)(iVar3 + 0x1b4) = uVar1;
          *(undefined4 *)(iVar3 + 0x10bc) = uVar1;
          *(undefined4 *)(iVar3 + 0x94) = *(undefined4 *)(iVar3 + 0x88);
          uVar1 = *(undefined4 *)(iVar3 + 100);
          *(undefined4 *)(iVar3 + 0x1d0) = uVar2;
          *(undefined4 *)(iVar3 + 0x1b8) = uVar2;
          *(undefined4 *)(iVar3 + 0x10c0) = uVar2;
          *(undefined4 *)(iVar3 + 0x1d4) = uVar1;
          *(undefined4 *)(iVar3 + 0x1bc) = uVar1;
          *(undefined4 *)(iVar3 + 0x10c4) = uVar1;
          *(undefined4 *)(iVar3 + 0xdf8) = DAT_0093b0cc;
          *(undefined4 *)(iVar3 + 0xdfc) = DAT_0093b0d0;
          uVar1 = DAT_0093b0d4;
          *(undefined4 *)(iVar3 + 0xe00) = DAT_0093b0d4;
          *(undefined4 *)(iVar3 + 0x68) = *(undefined4 *)(iVar3 + 0xdf8);
          *(undefined4 *)(iVar3 + 0x6c) = *(undefined4 *)(iVar3 + 0xdfc);
          *(undefined4 *)(iVar3 + 0x70) = uVar1;
          FUN_005728a0(iVar3);
          FUN_00572660(iVar3,0);
        }
      }
      else {
        FUN_0041c120(iVar3,*(undefined4 *)(PTR_DAT_00802c54 + 0x2ae8));
      }
      FUN_00595af0(iVar3,*(undefined4 *)(PTR_DAT_00802c54 + 0x2ab4));
      return iVar3;
    }
  }
  return 0;
}

