/* Ghidra pseudocode, not original source.
 * ev_32329224682956fa8cc17060d0cd356f2ceec3520653550ffb34c5179fbcb220
 * Entry: 0x4efda0; label: FUN_004efda0
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004efda0(void)

{
  undefined4 *in_EAX;
  undefined4 local_4;
  
  local_4 = CONCAT13(*(undefined1 *)in_EAX,
                     CONCAT12(*(undefined1 *)((int)in_EAX + 1),
                              CONCAT11(*(undefined1 *)((int)in_EAX + 2),
                                       *(undefined1 *)((int)in_EAX + 3))));
  *in_EAX = local_4;
  return;
}

