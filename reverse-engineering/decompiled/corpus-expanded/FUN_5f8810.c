/* Ghidra pseudocode, not original source.
 * ev_a45c3c1faa99142355c13bd889df9cc9cfbd82e1fed23ccee59d68361bef177f
 * Entry: 0x5f8810; label: FUN_005f8810
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_005f8810(void)

{
  undefined4 in_EAX;
  
  switch(in_EAX) {
  case 0:
    FUN_006e5340(0x16,1);
    FUN_006e5340(0xf,0);
    FUN_006e5340(0x1b,0);
    FUN_006e5340(7,0);
    FUN_006e5340(0xa8,0xf);
    return;
  case 1:
    FUN_006e5340(0x16,1);
    FUN_006e5340(0xf,0);
    FUN_006e5340(0x1b,0);
    FUN_006e5340(7,1);
    FUN_006e5340(0xe,1);
    FUN_006e5340(0x17,8);
    return;
  case 2:
    FUN_006e5340(0x16,1);
    FUN_006e5340(0xf,0);
    FUN_006e5340(0x1b,0);
    FUN_006e5340(7,1);
    FUN_006e5340(0xe,0);
    FUN_006e5340(0x17,5);
    return;
  case 4:
    FUN_006e5340(0x16,1);
    FUN_006e5340(0xf,1);
    FUN_006e5340(0x1b,1);
    FUN_006e5340(7,1);
    FUN_006e5340(0x17,4);
  }
  return;
}

