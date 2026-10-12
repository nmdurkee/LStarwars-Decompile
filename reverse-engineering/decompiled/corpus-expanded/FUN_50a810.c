/* Ghidra pseudocode, not original source.
 * ev_81eb7f72611438fc14464b4b3c9dc19cd531190571fee01318f31577736c1626
 * Entry: 0x50a810; label: FUN_0050a810
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0050a810(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = DAT_00921d7c;
  if (DAT_00921d7c == 0) {
    (&DAT_00800ac2)[*(short *)(param_1 + 0x14) * 0x1c] = 1;
  }
  else {
    (&DAT_00800ac2)[*(short *)(param_1 + 0x14) * 0x1c] = 0;
  }
  if ((DAT_00921e5c != 0) || (DAT_00802008 != 2)) {
    FUN_0050a450(param_1);
    iVar2 = DAT_00921d7c;
  }
  iVar1 = (int)*(short *)(param_1 + 8) - (int)*(short *)(param_1 + 0xc);
  if (*(int *)(param_1 + 100) == 0) {
    if ((*(int *)(param_1 + 0x68) != 0) && (iVar2 == 0)) {
      DAT_00800940 = DAT_00800954;
      FUN_00509830(0x3f8,1,0xffffffff);
    }
  }
  else {
    DAT_00800940 = DAT_00800954;
    if (*(short *)(param_1 + 10) == 0) {
      if (((&DAT_02989540)[iVar1] == 0) && (DAT_0080200c < DAT_008015a4)) {
        DAT_00800940 = DAT_0080095c;
        return;
      }
      DAT_00921dc0 = iVar1;
      FUN_00509830(0x3f0,1,0xffffffff);
      return;
    }
    if ((*(short *)(param_1 + 10) == *(short *)(param_1 + 0x12)) && (iVar2 == 0)) {
      FUN_00509830(0x3f8,1,0xffffffff);
      return;
    }
  }
  return;
}

