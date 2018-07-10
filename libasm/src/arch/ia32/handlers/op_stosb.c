/**
 * @file libasm/src/arch/ia32/handlers/op_stosb.c
 *
 * @ingroup IA32_instrs
**
*/
#include <libasm.h>
#include <libasm-int.h>

/**
  <instruction func="op_stosb" opcode="0xaa"/>
*/

int op_stosb(asm_instr *new, u_char *opcode, u_int len, asm_processor *proc)
{
  new->ptr_instr = opcode;
  new->instr = ASM_STOSB;
  new->len += 1;
  new->type = ASM_TYPE_STORE;

  new->len += asm_operand_fetch(&new->op[0], opcode, ASM_CONTENT_YDEST, new);
  new->len += asm_operand_fetch(&new->op[1], opcode, ASM_CONTENT_XSRC, new);

  return (new->len);
}
