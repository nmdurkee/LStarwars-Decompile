/* Ghidra pseudocode, not original source.
 * ev_81eb7f72611438fc14464b4b3c9dc19cd531190571fee01318f31577736c1626
 * Entry: 0x50af30; label: FUN_0050af30
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_0050af30(int param_1)

{
  if ((DAT_00921e5c == 0) && (DAT_00802008 == 2)) {
    if (*(int *)(param_1 + 100) == 0) {
      if (*(int *)(param_1 + 0x68) != 0) {
        FUN_00509830(0x3f9,1,0xffffffff);
        DAT_00800940 = DAT_00800954;
        return;
      }
    }
    else {
      DAT_00800940 = DAT_00800954;
      if (*(short *)(param_1 + 10) == 0) {
        DAT_00921dc0 = (int)*(short *)(param_1 + 8) - (int)*(short *)(param_1 + 0xc);
        if ((&DAT_02989540)[DAT_00921dc0] == 0) {
          DAT_00800940 = DAT_0080095c;
          return;
        }
        FUN_00509830(0x3f5,1,0xffffffff);
      }
      else if (*(short *)(param_1 + 10) == *(short *)(param_1 + 0x12)) {
        FUN_00509830(0x3f9,1,0xffffffff);
        return;
      }
    }
    return;
  }
  FUN_0050a650();
  return;
}

