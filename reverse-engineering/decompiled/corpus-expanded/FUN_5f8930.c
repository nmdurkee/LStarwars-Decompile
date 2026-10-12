/* Ghidra pseudocode, not original source.
 * ev_a45c3c1faa99142355c13bd889df9cc9cfbd82e1fed23ccee59d68361bef177f
 * Entry: 0x5f8930; label: FUN_005f8930
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005f8930(void)

{
  undefined4 in_EAX;
  
  _DAT_0080e690 = in_EAX;
  switch(in_EAX) {
  case 0:
    FUN_006e5340(7,1);
    FUN_006e5340(0xe,1);
    FUN_006e5340(0x17,4);
    return;
  case 1:
    FUN_006e5340(7,1);
    FUN_006e5340(0xe,0);
    FUN_006e5340(0x17,4);
    return;
  case 2:
    FUN_006e5340(7,1);
    FUN_006e5340(0xe,1);
    FUN_006e5340(0x17,8);
    return;
  case 3:
    FUN_006e5340(7,0);
  }
  return;
}

