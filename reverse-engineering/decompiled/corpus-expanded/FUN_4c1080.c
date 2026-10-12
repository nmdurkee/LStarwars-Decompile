/* Ghidra pseudocode, not original source.
 * ev_70591197c926ebc674651557d03c19c52d1cbc8417e398ad949c9ada842aa1a9
 * Entry: 0x4c1080; label: FUN_004c1080
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004c1080(void)

{
  int *in_EAX;
  uint uVar1;
  uint *puVar2;
  uint uVar3;
  int local_4;
  
  *in_EAX = 0;
  in_EAX[1] = 0;
  in_EAX[2] = 0;
  in_EAX[3] = 0;
  in_EAX[4] = 0;
  in_EAX[5] = 0;
  in_EAX[6] = 0;
  in_EAX[7] = 0;
  in_EAX[8] = 0;
  in_EAX[9] = 0;
  local_4 = 0;
  puVar2 = &DAT_009253b8;
  do {
    if ((&DAT_0087b6c8)[local_4] != '\0') {
      uVar1 = *puVar2;
      if (((DAT_008022c4 & uVar1) != 0) && (DAT_00951b50 == 0)) {
        in_EAX[8] = 1;
        return;
      }
      if ((DAT_008022c8 & uVar1) != 0) {
        in_EAX[9] = 1;
        return;
      }
      if (DAT_00951b50 == 0) {
        uVar3 = puVar2[-1] | puVar2[1];
        uVar1 = puVar2[2] | uVar1;
        if ((DAT_00802298 & uVar3) != 0) {
          in_EAX[4] = 1;
        }
        if ((DAT_0080229c & uVar3) != 0) {
          in_EAX[5] = 1;
        }
        if ((in_EAX[4] != 0) && (in_EAX[5] != 0)) {
          in_EAX[5] = 0;
          in_EAX[4] = 0;
        }
        if ((DAT_00802290 & uVar3) != 0) {
          in_EAX[6] = 1;
        }
        if ((DAT_00802294 & uVar3) != 0) {
          in_EAX[7] = 1;
        }
        if ((in_EAX[6] != 0) && (in_EAX[7] != 0)) {
          in_EAX[7] = 0;
          in_EAX[6] = 0;
        }
        if ((DAT_00802298 & uVar1) != 0) {
          *in_EAX = 1;
        }
        if ((DAT_0080229c & uVar1) != 0) {
          in_EAX[1] = 1;
        }
        if ((*in_EAX != 0) && (in_EAX[1] != 0)) {
          in_EAX[1] = 0;
          *in_EAX = 0;
        }
        if ((DAT_00802290 & uVar1) != 0) {
          in_EAX[2] = 1;
        }
        if ((DAT_00802294 & uVar1) != 0) {
          in_EAX[3] = 1;
        }
        if ((in_EAX[2] != 0) && (in_EAX[3] != 0)) {
          in_EAX[3] = 0;
          in_EAX[2] = 0;
        }
      }
    }
    local_4 = local_4 + 1;
    puVar2 = puVar2 + 0x18;
    if (0x925477 < (int)puVar2) {
      return;
    }
  } while( true );
}

