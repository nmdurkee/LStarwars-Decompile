/* Ghidra pseudocode, not original source.
 * ev_07ae9e2e04489686a5b927c1fa0593b6d570aedc464c7aee9c2d2b7a39d3047e
 * Entry: 0x429740; label: FUN_00429740
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00429740(void)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(PTR_DAT_00802c54 + 0x128);
  if (iVar1 == DAT_0087b114) {
    _DAT_00810d9c = 0x40400000;
    _DAT_00810d98 = 0x41b40000;
    return 1;
  }
  iVar2 = *(int *)(PTR_DAT_00802c54 + 300);
  if (iVar2 != 0) {
    if ((iVar2 == DAT_0087af78) || (iVar2 == DAT_0087b01c)) {
      _DAT_00810d9c = 0x41c80000;
      _DAT_00810d98 = 0x42fa0000;
      return 1;
    }
    if ((iVar2 != 0) && (iVar2 == DAT_0087af84)) {
      _DAT_00810d9c = 0x42c80000;
      _DAT_00810d98 = 0x437a0000;
      return 1;
    }
  }
  if (iVar1 == DAT_0087b1b4) {
    _DAT_00810d9c = 0x40a00000;
  }
  else {
    if (iVar2 != 0) {
      if (iVar2 == DAT_0087afac) {
        _DAT_00810d9c = 0x40400000;
        _DAT_00810d98 = 0x41700000;
        return 1;
      }
      if (iVar2 != 0) {
        if (iVar2 == DAT_0087afbc) {
          _DAT_00810d9c = 0x41c80000;
          _DAT_00810d98 = 0x43160000;
          return 1;
        }
        if ((iVar2 != 0) && (iVar2 == DAT_0087afcc)) {
          _DAT_00810d98 = 0x41a00000;
          _DAT_00810d9c = 0x40400000;
          return 1;
        }
      }
    }
    if (iVar1 == DAT_0087b26c) {
      _DAT_00810d9c = 0x40f00000;
      _DAT_00810d98 = 0x41a00000;
      return 1;
    }
    if (iVar1 == DAT_0087b274) {
      _DAT_00810d9c = 0x40f00000;
      _DAT_00810d98 = 0x425c0000;
      return 1;
    }
    if ((iVar2 == 0) || (iVar2 != DAT_0087afd4)) {
      if (iVar1 == DAT_0087b294) {
        _DAT_00810d9c = 0x40800000;
        _DAT_00810d98 = 0x41400000;
        return 1;
      }
      if ((iVar1 == DAT_0087b298) || (iVar1 == DAT_0087b29c)) {
        _DAT_00810d9c = 0x41700000;
        _DAT_00810d98 = 0x42340000;
        return 1;
      }
      if (iVar1 == DAT_0087b2a0) {
        _DAT_00810d9c = 0x40400000;
        _DAT_00810d98 = 0x41400000;
        return 1;
      }
      if (iVar2 != 0) {
        if (iVar2 == DAT_0087afdc) {
          _DAT_00810d9c = 0x42480000;
          _DAT_00810d98 = 0x43480000;
          return 1;
        }
        if ((iVar2 != 0) &&
           ((((iVar2 == DAT_0087afe4 || (iVar2 == DAT_0087afe8)) || (iVar2 == DAT_0087afec)) ||
            ((iVar2 == DAT_0087b040 || (iVar2 == DAT_0087b03c)))))) {
          _DAT_00810d9c = 0x40800000;
          _DAT_00810d98 = 0x42200000;
          return 1;
        }
      }
      return 0;
    }
    _DAT_00810d9c = 0x41700000;
  }
  _DAT_00810d98 = 0x42480000;
  return 1;
}

