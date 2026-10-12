/* Ghidra pseudocode, not original source.
 * ev_1e128395f166d68d7029ddd19e18d2d5e170338b26e7199f616481a8a2050617
 * Entry: 0x4eae80; label: FUN_004eae80
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004eae80(void)

{
  switch(*DAT_0088a590) {
  case 0:
  case 4:
    FUN_005579d0(DAT_0087a90c);
    break;
  case 1:
    FUN_00557960(DAT_0087a90c);
    FUN_00557960(DAT_0087a910);
    FUN_00557960(DAT_0087a914);
    return;
  case 2:
    FUN_00557960(DAT_0087a90c);
    break;
  case 3:
    FUN_00557960(DAT_0087a90c);
    FUN_005579d0(DAT_0087a910);
    FUN_00557960(DAT_0087a914);
    return;
  default:
    goto switchD_004eae90_default;
  }
  FUN_005579d0(DAT_0087a910);
  FUN_005579d0(DAT_0087a914);
switchD_004eae90_default:
  return;
}

