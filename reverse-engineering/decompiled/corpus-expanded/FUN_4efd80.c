/* Ghidra pseudocode, not original source.
 * ev_32329224682956fa8cc17060d0cd356f2ceec3520653550ffb34c5179fbcb220
 * Entry: 0x4efd80; label: FUN_004efd80
 * Boundary hypotheses: reports/native-boundary-seeds.json.
 */

void FUN_004efd80(void)

{
  undefined2 *in_EAX;
  undefined2 local_4;
  
  local_4 = CONCAT11(*(undefined1 *)in_EAX,*(undefined1 *)((int)in_EAX + 1));
  *in_EAX = local_4;
  return;
}

