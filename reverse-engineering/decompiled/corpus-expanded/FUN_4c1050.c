/* Ghidra pseudocode, not original source.
 * ev_70591197c926ebc674651557d03c19c52d1cbc8417e398ad949c9ada842aa1a9
 * Entry: 0x4c1050; label: FUN_004c1050
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

bool FUN_004c1050(void)

{
  int in_EAX;
  int iVar1;
  
  if (in_EAX == DAT_007f17d4) {
    return DAT_0086e4e5 != '\0';
  }
  iVar1 = FUN_00594870();
  return iVar1 != 0;
}

