/* Ghidra pseudocode, not original source.
 * ev_57ca11fd66234800334e5f23d40b47e1bf5f9001c22ff37fd2f45222df4b5a02
 * Entry: 0x602f50; label: FUN_00602f50
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

undefined4 FUN_00602f50(int param_1)

{
  if (param_1 < 0x1001) {
    if (param_1 == 0x1000) {
      return 4;
    }
    switch(param_1) {
    case 1:
      return 0xc;
    case 3:
      return 0xa0;
    case 0x11:
      return 0x10;
    case 0x40:
      return 8;
    case 0x4b:
    case 0x59:
      return 0x24;
    case 0x51:
      return 0x18;
    case 0x53:
      return 0x1c;
    case 0x5d:
      return 0x38;
    case 0xd9:
      return 0x2c;
    case 0xdd:
      return 0x40;
    case -1:
    case 0:
      return 0;
    }
  }
  FUN_005f7490();
  return 0;
}

