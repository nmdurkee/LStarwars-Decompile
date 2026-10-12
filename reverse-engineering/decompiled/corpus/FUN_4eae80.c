/* Ghidra analysis pseudocode, not original source.
 * ev_9f32143acc641fc8c09d2d2f6cbbcb37d8d4315dda9a3c3d8b53f1525d5ab059
 * Entry: 0x4eae80; label: FUN_004eae80
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

